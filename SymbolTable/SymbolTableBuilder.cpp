#include "SymbolTableBuilder.h"
#include "ASTIncludes.h"
#include "include/ClassInfo.h"
#include "include/MethodInfo.h"
#include "include/VariableInfo.h"
#include "include/Symbol.h"

#include <cassert>


CTable *CSymbolTableBuilder::Build( const CGoal *acceptable )
{
    assert( acceptable != nullptr );

    scopes.push_back( new CBlockScope() );
    acceptable->Accept( this );

    table = new CTable;
    table->AddNewBlockScope( scopes.back() );

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
    CSymbol* methodName = CSymbol::GetIntern( "main" );
    CSymbol* returnType = CSymbol::GetIntern( "void" );
    CSymbol* argName = CSymbol::GetIntern( acceptable->argName->identifier );
    CSymbol* argType = CSymbol::GetIntern( "String[]" );

    auto argInfo = new CVariableInfo( argName, argType );
    auto methodInfo = new CMethodInfo( methodName, returnType );

    auto scope = new CBlockScope;
    scope->AddVariable( argName, argInfo );
    scope->AddMethod( methodName, methodInfo );

    auto classInfo = new CClassInfo( className );
    classInfo->SetScope( scope );

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

    scopes.push_back( new CBlockScope );
    acceptable->methodDeclarationS->Accept( this );
    acceptable->varDeclarationS->Accept( this );
    classInfo->SetScope( scopes.back() );
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

    CSymbol* methodRetTypeName = terminalSymbol;

    auto methodInfo = new CMethodInfo( methodName, methodRetTypeName );
}

void CSymbolTableBuilder::Visit( const CVarDeclarationList *acceptable )
{

}

void CSymbolTableBuilder::Visit( const CVarDeclaration *acceptable )
{

}
