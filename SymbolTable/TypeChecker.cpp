#include <iostream>
#include "TypeChecker.h"
#include "ASTIncludes.h"

const CSymbol* const TypeChecker::booleanSymbol = CSymbol::GetIntern( "boolean" );
const CSymbol* const TypeChecker::intSymbol = CSymbol::GetIntern( "int" );
const CSymbol* const TypeChecker::intArraySymbol = CSymbol::GetIntern( "int[]" );


void TypeChecker::Run( const CGoal *acceptable, CSymbolTable *_table )
{
    assert( acceptable != nullptr );
    assert( _table != nullptr );

    table = _table;
    acceptable->Accept( this );
}

void TypeChecker::Visit( const CGoal *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->mainClass != nullptr );

    acceptable->mainClass->Accept( this );

    if( acceptable->classDeclarationS != nullptr ) {
        acceptable->classDeclarationS->Accept( this );
    }
}

void TypeChecker::Visit( const CMainClass *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->className != nullptr );

    const CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );
    CClassInfo* classInfo = table->TryResolveClass( className );

    assert( classInfo != nullptr );
    table->PushBlockScope( classInfo->GetScope() );

    if( acceptable->statementS != nullptr ) {
        acceptable->statementS->Accept( this );
    }

    table->PopBlockScope();
}

void TypeChecker::Visit( const CClassDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto classDeclaration : acceptable->children ) {
        classDeclaration->Accept( this );
    }
}

void TypeChecker::Visit( const CStatementList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto statement : acceptable->children ) {
        statement->Accept( this );
    }
}

void TypeChecker::Visit( const CClassDeclaration *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->className != nullptr );

    const CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );
    CClassInfo* classInfo = table->TryResolveClass( className );

    assert( classInfo != nullptr );
    table->PushBlockScope( classInfo->GetScope() );

    if( acceptable->methodDeclarationS != nullptr ) {
        acceptable->methodDeclarationS->Accept( this );
    }

    table->PopBlockScope();
}

void TypeChecker::Visit( const CMethodDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto methodDeclaration : acceptable->children ) {
        methodDeclaration->Accept( this );
    }
}

void TypeChecker::Visit( const CMethodDeclaration *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->returnExpression != nullptr );
    assert( acceptable->methodIdentifier != nullptr );

    const CSymbol* methodName = CSymbol::GetIntern( acceptable->methodIdentifier->identifier );
    CMethodInfo* methodInfo = table->TryResolveMethod( methodName );

    assert( methodInfo != nullptr );
    table->PushBlockScope( methodInfo->GetScope() );

    if( acceptable->statementS != nullptr ) {
        acceptable->statementS->Accept( this );
    }

    acceptable->returnExpression->Accept( this );
    if( lastValidExpressionType != nullptr ) {
        if( methodInfo->GetRetTypeName() != lastValidExpressionType ) {
            std::cerr << "Invalid return type" << std::endl;
        }
    }

    table->PopBlockScope();
}

void TypeChecker::Visit( const CCurlyBraceStatement *acceptable )
{
    assert( acceptable != nullptr );

    if( acceptable->statementS != nullptr ) {
        acceptable->statementS->Accept( this );
    }
}

void TypeChecker::Visit( const CIfElseStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->condition != nullptr );
    assert( acceptable->ifStatement != nullptr );
    assert( acceptable->elseStatement != nullptr );

    acceptable->condition->Accept( this );
    if( lastValidExpressionType != nullptr ) {
        if( lastValidExpressionType != booleanSymbol ) {
            std::cerr << "Invalid type of if-statement condition" << std::endl;
        }
    }
    acceptable->ifStatement->Accept( this );
    acceptable->elseStatement->Accept( this );
}

void TypeChecker::Visit( const CWhileStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->condition != nullptr );
    assert( acceptable->statement != nullptr );

    acceptable->condition->Accept( this );
    if( lastValidExpressionType != nullptr ) {
        if( lastValidExpressionType != booleanSymbol ) {
            std::cerr << "Invalid type of while-statement condition" << std::endl;
        }
    }
    acceptable->statement->Accept( this );
}

void TypeChecker::Visit( const CPrintlnStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    if( lastValidExpressionType != nullptr ) {
        if( lastValidExpressionType != intSymbol
            && lastValidExpressionType != booleanSymbol
            && lastValidExpressionType != intArraySymbol )
        {
            std::cerr << "Println supports only builtin types: int, boolean, int[]." << std::endl;
        }
    }
}

void TypeChecker::Visit( const CVarAssignmentStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->varName != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );

    const CSymbol* name = CSymbol::GetIntern( acceptable->varName->identifier );
    CSymbolTable::SymbolType nameType = table->ResolveType( name );
    if( nameType == CSymbolTable::SymbolType::VARIABLE ) {
        const CVariableInfo* varInfo = table->TryResolveVariable( name );
        assert( varInfo != nullptr );
        if( lastValidExpressionType != nullptr ) {
            if( lastValidExpressionType != varInfo->GetTypeName() ) {
                std::cerr << "Mismatched types in assignment statement." << std::endl;
            }
        }
    } else if( nameType == CSymbolTable::SymbolType::UNDECLARED ) {
        std::cout << "Use of undeclared identifier" << std::endl;
    } else {
        std::cout << "Name is not assignable" << std::endl;
    }
}

void TypeChecker::Visit( const CArrayAssignmentStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->arrayName != nullptr );
    assert( acceptable->indexExpression != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->indexExpression->Accept( this );
    const CSymbol* indexExpressionType = lastValidExpressionType;

    acceptable->expression->Accept( this );
    const CSymbol* expressionType = lastValidExpressionType;

    const CSymbol* name = CSymbol::GetIntern( acceptable->arrayName->identifier );
    CSymbolTable::SymbolType nameType = table->ResolveType( name );
    if( nameType == CSymbolTable::SymbolType::VARIABLE ) {
        const CVariableInfo* varInfo = table->TryResolveVariable( name );
        assert( varInfo != nullptr );
        if( varInfo->GetTypeName() != intArraySymbol ) {
            std::cout << "Variable does not support indexing" << std::endl;
        } else  {
            if( indexExpressionType != nullptr ) {
                if( indexExpressionType != intSymbol ) {
                    std::cout << "Array subscript is not an integer." << std::endl;
                }
            }
            if( expressionType != nullptr ) {
                if( expressionType != intSymbol ) {
                    std::cout << "Mismatched types in assignment statement." << std::endl;
                }
            }
        }
    } else if( nameType == CSymbolTable::SymbolType::UNDECLARED ) {
        std::cout << "Use of undeclared identifier" << std::endl;
    } else {
        std::cout << "Name is not assignable" << std::endl;
    }
}

void TypeChecker::Visit( const CBinaryOpExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->left != nullptr );
    assert( acceptable->right != nullptr );

    acceptable->left->Accept( this );
    const CSymbol* leftType = lastValidExpressionType;

    acceptable->right->Accept( this );
    const CSymbol* rightType = lastValidExpressionType;

    switch( acceptable->opType ) {
        case CBinaryOpExpression::OpType::AND:
            lastValidExpressionType = booleanSymbol;
            if( leftType != nullptr && leftType != booleanSymbol ) {
                std::cerr << "Expression must be of type 'boolean'" << std::endl;
                lastValidExpressionType = nullptr;
            }
            if( rightType != nullptr && rightType != booleanSymbol ) {
                std::cerr << "Expression must be of type 'boolean'" << std::endl;
                lastValidExpressionType = nullptr;
            }
            break;

        case CBinaryOpExpression::OpType::LESS:
        case CBinaryOpExpression::OpType::MINUS:
        case CBinaryOpExpression::OpType::MULTIPLY:
        case CBinaryOpExpression::OpType::PLUS:
            lastValidExpressionType = intSymbol;
            if( leftType != nullptr && leftType != intSymbol ) {
                std::cerr << "Expression must be of numeric type" << std::endl;
                lastValidExpressionType = nullptr;
            }
            if( rightType != nullptr && rightType != intSymbol ) {
                std::cerr << "Expression must be of numeric type" << std::endl;
                lastValidExpressionType = nullptr;
            }
            break;
    }
}

void TypeChecker::Visit( const CSquarebracketsExpression *acceptable )
{

}
