#include "SymbolTableBuilder.h"
#include "ASTIncludes.h"
#include "include/ClassInfo.h"
#include "include/MethodInfo.h"
#include "include/VariableInfo.h"
#include "include/Symbol.h"

#include <cassert>
#include <iostream>



CSymbolTableBuilder::CSymbolTableBuilder() :
    currentMethodInfo( nullptr ),
    offset( 0 )
{
    //
}


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

    const CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );
    auto classInfo = new CClassInfo( className );

    const CSymbol* methodName = CSymbol::GetIntern( "main" );
    const CSymbol* returnType = CSymbol::GetIntern( "void" );
    const CSymbol* argName = CSymbol::GetIntern( acceptable->argName->identifier );
    const CSymbol* argType = CSymbol::GetIntern( "String[]" );
    auto argInfo = new CVariableInfo( argName, argType, 0 );
    auto methodInfo = new CMethodInfo( methodName, returnType );
    methodInfo->GetScope()->AddVariable( argName, argInfo );
    methodInfo->RegisterAsParameter( argName );
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

    const CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );

    auto classInfo = new CClassInfo( className );

    scopes.push_back( classInfo->GetScope() );
    if( acceptable->methodDeclarationS != nullptr ) {
        acceptable->methodDeclarationS->Accept( this );
    }
    if( acceptable->varDeclarationS != nullptr ) {
        acceptable->varDeclarationS->Accept( this );
    }
    scopes.pop_back();

    if( acceptable->extension != nullptr ) {
        currentClassInfo = classInfo;
        acceptable->extension->Accept( this );
        currentClassInfo = nullptr;
    }

    CBlockScope::SymbolType type = scopes.back()->ResolveType( className );
    if( type == CBlockScope::SymbolType::UNDECLARED ) {
        scopes.back()->AddClass( className, classInfo );
    } else {
        onNameRedefinitionError( className, scopes.back() );
    }
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

    const CSymbol* methodName = CSymbol::GetIntern( acceptable->methodIdentifier->identifier );

    const CSymbol* methodRetTypeName = CSymbol::GetIntern( acceptable->returnType->GetString() );
    auto methodInfo = new CMethodInfo( methodName, methodRetTypeName );

    scopes.push_back( methodInfo->GetScope() );
    if( acceptable->varDeclarationS != nullptr ) {
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->params != nullptr ) {
        currentMethodInfo = methodInfo;
        acceptable->params->Accept( this );
        currentMethodInfo = nullptr;
    }
    scopes.pop_back();

    CBlockScope::SymbolType type = scopes.back()->ResolveType( methodName );
    if( type == CBlockScope::SymbolType::UNDECLARED ) {
        scopes.back()->AddMethod( methodName, methodInfo );
    } else {
        onNameRedefinitionError( methodName, scopes.back() );
    }
}

void CSymbolTableBuilder::Visit( const CVarDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    offset = 0;
    for( auto varDeclaration : acceptable->children ) {
        varDeclaration->Accept( this );
        ++offset;
    }
}

void CSymbolTableBuilder::Visit( const CVarDeclaration *acceptable )
{
    assert( acceptable != nullptr );

    const CSymbol* varName = CSymbol::GetIntern( acceptable->identifier->identifier );
    const CSymbol* typeName = CSymbol::GetIntern( acceptable->type->GetString() );

    auto varInfo = new CVariableInfo( varName, typeName, offset );

    CBlockScope::SymbolType type = scopes.back()->ResolveType( varName );
    if( type == CBlockScope::SymbolType::UNDECLARED ) {
        scopes.back()->AddVariable( varName, varInfo );
    } else {
        onNameRedefinitionError( varName, scopes.back() );
    }
}

void CSymbolTableBuilder::Visit( const CParamList* acceptable )
{
    assert( acceptable != nullptr );

    offset = 0;
    for( auto param : acceptable->children ) {
        param->Accept( this );
        ++offset;
    }
}

void CSymbolTableBuilder::Visit( const CParam* acceptable )
{
    assert( acceptable != nullptr );

    const CSymbol* varName = CSymbol::GetIntern( acceptable->identifier->identifier );
    const CSymbol* typeName = CSymbol::GetIntern( acceptable->type->GetString() );

    auto varInfo = new CVariableInfo( varName, typeName, offset );

    CBlockScope::SymbolType type = scopes.back()->ResolveType( varName );
    if( type == CBlockScope::SymbolType::UNDECLARED ) {
        scopes.back()->AddVariable( varName, varInfo );
        currentMethodInfo->RegisterAsParameter( varName );
    } else {
        onNameRedefinitionError( varName, scopes.back() );
    }
}

void CSymbolTableBuilder::onNameRedefinitionError( const CSymbol *name, const CBlockScope *scope )
{
    assert( name != nullptr );
    assert( scope != nullptr );

    CBlockScope::SymbolType type = scope->ResolveType( name );
    std::string prevDefinition;
    switch( type ) {
        case CBlockScope::SymbolType::VARIABLE:
            prevDefinition = scope->TryResolveVariable( name )->GetStringRepresentation();
            break;
        case CBlockScope::SymbolType::METHOD:
            prevDefinition = scope->TryResolveMethod( name )->GetStringRepresentation();
            break;
        case CBlockScope::SymbolType::CLASS:
            prevDefinition = scope->TryResolveClass( name )->GetStringRepresentation();
            break;
        default:
            break;
    }
    std::cerr << "Redefinition of name '" << name->GetString() << "'. "
              << "Previously defined as '" << prevDefinition << "'."
              << std::endl;
}

void CSymbolTableBuilder::Visit( const CExtension* acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->className != nullptr );

    const CSymbol* parentName = CSymbol::GetIntern( acceptable->className->identifier );

    currentClassInfo->SetParent( parentName );
}
