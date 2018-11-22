#include "SymbolTableBuilder.h"
#include "ASTIncludes.h"
#include "include/ClassInfo.h"
#include "include/MethodInfo.h"
#include "include/VariableInfo.h"
#include "include/Symbol.h"

#include <cassert>


std::unique_ptr<CSymbolTable> CSymbolTableBuilder::Build( const CGoal *acceptable )
{
    assert( acceptable != nullptr );

    scopes.push_back( new CBlockScope() );
    acceptable->Accept( this );

    auto table = std::make_unique<CSymbolTable>();
    table->PushBlockScope(scopes.back());

    return table;
}

void CSymbolTableBuilder::Visit( const CGoal *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->mainClass != nullptr );

    acceptable->mainClass->Accept( this );

    if( acceptable->classDeclarationS != nullptr ) {
        acceptable->classDeclarationS->Accept( this );
    }
}

void CSymbolTableBuilder::Visit( const CMainClass *acceptable )
{
    assert( acceptable != nullptr );

    CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );
    auto classInfo = new CClassInfo( className );

    CSymbol* methodName = CSymbol::GetIntern( "main" );
    CSymbol* returnType = CSymbol::GetIntern( "void" );
    CSymbol* argName = CSymbol::GetIntern( acceptable->argName->identifier );
    CSymbol* argType = CSymbol::GetIntern( "String[]" );
    auto argInfo = new CVariableInfo( argName, argType );
    auto methodInfo = new CMethodInfo( methodName, returnType );
    methodInfo->GetScope()->AddVariable( argName, argInfo );
    classInfo->GetScope()->AddMethod( methodName, methodInfo );

    scopes.back()->AddClass( className, classInfo );
}

void CSymbolTableBuilder::Visit( const CClassDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto classDeclaration : acceptable->children ) {
        classDeclaration->Accept( this );
    }
}

void CSymbolTableBuilder::Visit( const CClassDeclaration *acceptable )
{
    assert( acceptable != nullptr );

    CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );

    auto classInfo = new CClassInfo( className );

    scopes.push_back( classInfo->GetScope() );
    if( acceptable->methodDeclarationS != nullptr ) {
        acceptable->methodDeclarationS->Accept( this );
    }
    if( acceptable->varDeclarationS != nullptr ) {
        acceptable->varDeclarationS->Accept( this );
    }
    scopes.pop_back();

    scopes.back()->AddClass( className, classInfo );
}

void CSymbolTableBuilder::Visit( const CMethodDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto methodDeclaration : acceptable->children ) {
        methodDeclaration->Accept( this );
    }
}

void CSymbolTableBuilder::Visit( const CMethodDeclaration *acceptable )
{
    assert( acceptable != nullptr );

    CSymbol* methodName = CSymbol::GetIntern( acceptable->methodIdentifier->identifier );

    CSymbol* methodRetTypeName = CSymbol::GetIntern( acceptable->returnType->GetString() );
    auto methodInfo = new CMethodInfo( methodName, methodRetTypeName );

    scopes.push_back( methodInfo->GetScope() );
    if( acceptable->varDeclarationS != nullptr ) {
        acceptable->varDeclarationS->Accept( this );
    }
    scopes.pop_back();

    scopes.back()->AddMethod( methodName, methodInfo );
}

void CSymbolTableBuilder::Visit( const CVarDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto varDeclaration : acceptable->children ) {
        varDeclaration->Accept( this );
    }
}

void CSymbolTableBuilder::Visit( const CVarDeclaration *acceptable )
{
    assert( acceptable != nullptr );

    CSymbol* varName = CSymbol::GetIntern( acceptable->identifier->identifier );
    CSymbol* typeName = CSymbol::GetIntern( acceptable->type->GetString() );

    auto varInfo = new CVariableInfo( varName, typeName );

    scopes.back()->AddVariable( varName, varInfo );
}
