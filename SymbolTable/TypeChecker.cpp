#include <iostream>
#include "TypeChecker.h"
#include "ASTIncludes.h"

const CSymbol* const CTypeChecker::booleanSymbol = CSymbol::GetIntern( "boolean" );
const CSymbol* const CTypeChecker::intSymbol = CSymbol::GetIntern( "int" );
const CSymbol* const CTypeChecker::intArraySymbol = CSymbol::GetIntern( "int[]" );


void CTypeChecker::Run( const CGoal *acceptable, CSymbolTable *_table )
{
    assert( acceptable != nullptr );
    assert( _table != nullptr );

    table = _table;
    currentClass = nullptr;

    acceptable->Accept( this );
}

void CTypeChecker::Visit( const CGoal *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->mainClass != nullptr );

    acceptable->mainClass->Accept( this );

    if( acceptable->classDeclarationS != nullptr ) {
        acceptable->classDeclarationS->Accept( this );
    }
}

void CTypeChecker::Visit( const CMainClass *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->className != nullptr );

    const CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );
    CClassInfo* classInfo = table->TryResolveClass( className );
    currentClass = classInfo;

    assert( classInfo != nullptr );
    table->PushBlockScope( classInfo->GetScope() );

    if( acceptable->statementS != nullptr ) {
        acceptable->statementS->Accept( this );
    }

    table->PopBlockScope();
}

void CTypeChecker::Visit( const CClassDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto classDeclaration : acceptable->children ) {
        classDeclaration->Accept( this );
    }
}

void CTypeChecker::Visit( const CStatementList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto statement : acceptable->children ) {
        statement->Accept( this );
    }
}

void CTypeChecker::Visit( const CClassDeclaration *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->className != nullptr );

    const CSymbol* className = CSymbol::GetIntern( acceptable->className->identifier );
    CClassInfo* classInfo = table->TryResolveClass( className );
    currentClass = classInfo;

    assert( classInfo != nullptr );
    table->PushBlockScope( classInfo->GetScope() );

    if( acceptable->methodDeclarationS != nullptr ) {
        acceptable->methodDeclarationS->Accept( this );
    }

    table->PopBlockScope();
}

void CTypeChecker::Visit( const CMethodDeclarationList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto methodDeclaration : acceptable->children ) {
        methodDeclaration->Accept( this );
    }
}

void CTypeChecker::Visit( const CMethodDeclaration *acceptable )
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
    if( expressionTypes.back() != nullptr ) {
        if( methodInfo->GetRetTypeName() != expressionTypes.back() ) {
            std::cerr << "Invalid return type" << std::endl;
        }
    }
    expressionTypes.pop_back();

    table->PopBlockScope();
}

void CTypeChecker::Visit( const CCurlyBraceStatement *acceptable )
{
    assert( acceptable != nullptr );

    if( acceptable->statementS != nullptr ) {
        acceptable->statementS->Accept( this );
    }
}

void CTypeChecker::Visit( const CIfElseStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->condition != nullptr );
    assert( acceptable->ifStatement != nullptr );
    assert( acceptable->elseStatement != nullptr );

    acceptable->condition->Accept( this );
    if( expressionTypes.back() != nullptr ) {
        if( expressionTypes.back() != booleanSymbol ) {
            std::cerr << "Invalid type of if-statement condition" << std::endl;
        }
    }
    expressionTypes.pop_back();
    acceptable->ifStatement->Accept( this );
    acceptable->elseStatement->Accept( this );
}

void CTypeChecker::Visit( const CWhileStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->condition != nullptr );
    assert( acceptable->statement != nullptr );

    acceptable->condition->Accept( this );
    if( expressionTypes.back() != nullptr ) {
        if( expressionTypes.back() != booleanSymbol ) {
            std::cerr << "Invalid type of while-statement condition" << std::endl;
        }
    }
    expressionTypes.pop_back();
    acceptable->statement->Accept( this );
}

void CTypeChecker::Visit( const CPrintlnStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    if( expressionTypes.back() != nullptr ) {
        if( expressionTypes.back() != intSymbol
            && expressionTypes.back() != booleanSymbol
            && expressionTypes.back() != intArraySymbol )
        {
            std::cerr << "Println supports only builtin types: int, boolean, int[]." << std::endl;
        }
    }
    expressionTypes.pop_back();
}

void CTypeChecker::Visit( const CVarAssignmentStatement *acceptable )
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
        if( expressionTypes.back() != nullptr ) {
            if( expressionTypes.back() != varInfo->GetTypeName() ) {
                std::cerr << "Mismatched types in assignment statement." << std::endl;
            }
        }
    } else if( nameType == CSymbolTable::SymbolType::UNDECLARED ) {
        std::cerr << "Use of undeclared identifier" << std::endl;
    } else {
        std::cerr << "Name is not assignable" << std::endl;
    }
    expressionTypes.pop_back();
}

void CTypeChecker::Visit( const CArrayAssignmentStatement *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->arrayName != nullptr );
    assert( acceptable->indexExpression != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->indexExpression->Accept( this );
    const CSymbol* indexExpressionType = expressionTypes.back();
    expressionTypes.pop_back();

    acceptable->expression->Accept( this );
    const CSymbol* expressionType = expressionTypes.back();
    expressionTypes.pop_back();

    const CSymbol* name = CSymbol::GetIntern( acceptable->arrayName->identifier );
    CSymbolTable::SymbolType nameType = table->ResolveType( name );
    if( nameType == CSymbolTable::SymbolType::VARIABLE ) {
        const CVariableInfo* varInfo = table->TryResolveVariable( name );
        assert( varInfo != nullptr );
        if( varInfo->GetTypeName() != intArraySymbol ) {
            std::cerr << "Variable is not subscriptable." << std::endl;
        } else  {
            if( indexExpressionType != nullptr ) {
                if( indexExpressionType != intSymbol ) {
                    std::cerr << "Array subscript is not an integer." << std::endl;
                }
            }
            if( expressionType != nullptr ) {
                if( expressionType != intSymbol ) {
                    std::cerr << "Mismatched types in assignment statement." << std::endl;
                }
            }
        }
    } else if( nameType == CSymbolTable::SymbolType::UNDECLARED ) {
        std::cerr << "Use of undeclared identifier" << std::endl;
    } else {
        std::cerr << "Name is not assignable" << std::endl;
    }
}

void CTypeChecker::Visit( const CBinaryOpExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->left != nullptr );
    assert( acceptable->right != nullptr );

    acceptable->left->Accept( this );
    const CSymbol* leftType = expressionTypes.back();
    expressionTypes.pop_back();

    acceptable->right->Accept( this );
    const CSymbol* rightType = expressionTypes.back();
    expressionTypes.pop_back();

    const CSymbol* type = nullptr;
    switch( acceptable->opType ) {
        case CBinaryOpExpression::OpType::AND:
            type = booleanSymbol;
            if( leftType != nullptr && leftType != booleanSymbol ) {
                std::cerr << "Expression must be of type 'boolean'" << std::endl;
                type = nullptr;
            }
            if( rightType != nullptr && rightType != booleanSymbol ) {
                std::cerr << "Expression must be of type 'boolean'" << std::endl;
                type = nullptr;
            }
            break;

        case CBinaryOpExpression::OpType::LESS:
            type = booleanSymbol;
            if( leftType != nullptr && leftType != intSymbol ) {
                std::cerr << "Expression must be of numeric type" << std::endl;
                type = nullptr;
            }
            if( rightType != nullptr && rightType != intSymbol ) {
                std::cerr << "Expression must be of numeric type" << std::endl;
                type = nullptr;
            }
            break;

        case CBinaryOpExpression::OpType::MINUS:
        case CBinaryOpExpression::OpType::MULTIPLY:
        case CBinaryOpExpression::OpType::PLUS:
            type = intSymbol;
            if( leftType != nullptr && leftType != intSymbol ) {
                std::cerr << "Expression must be of numeric type" << std::endl;
                type = nullptr;
            }
            if( rightType != nullptr && rightType != intSymbol ) {
                std::cerr << "Expression must be of numeric type" << std::endl;
                type = nullptr;
            }
            break;
    }
    expressionTypes.push_back( type );
}

void CTypeChecker::Visit( const CSquarebracketsExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );
    assert( acceptable->squarebraketsExpression != nullptr );

    acceptable->expression->Accept( this );
    const CSymbol* exprType = expressionTypes.back();
    expressionTypes.pop_back();

    acceptable->squarebraketsExpression->Accept( this );
    const CSymbol* braketsExprType = expressionTypes.back();
    expressionTypes.pop_back();

    const CSymbol* type = intSymbol;
    if( exprType != nullptr ) {
        if( exprType != intArraySymbol ) {
            std::cerr << "Variable is not subscriptable." << std::endl;
            type = nullptr;
        } else {
            if( braketsExprType != intSymbol ) {
                std::cerr << "Array subscript is not an integer." << std::endl;
                type = nullptr;
            }
        }
    }
    expressionTypes.push_back( type );
}

void CTypeChecker::Visit( const CLengthExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    const CSymbol* expressionType = expressionTypes.back();
    expressionTypes.pop_back();

    const CSymbol* type = intSymbol;
    if( expressionType != nullptr ) {
        if( expressionType != intArraySymbol ) {
            std::cerr << "Only array type support 'length'." << std::endl;
            type = nullptr;
        }
    }
    expressionTypes.push_back( type );
}

void CTypeChecker::Visit( const CCallExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );
    assert( acceptable->identifier != nullptr );

//    acceptable->expression->Accept( this );
//    const CSymbol* expressionTypeSymbol = expressionTypes.back();
//    expressionTypes.pop_back();
//
//    acceptable->expressionParamS->Accept( this );
//
//    if( expressionTypeSymbol != nullptr ) {
//        const CSymbolTable::SymbolType expressionType = table->ResolveType( expressionTypeSymbol );
//
//    }
//
//
//    if(  )
//
//    const CSymbol* identifierSymbol = CSymbol::GetIntern( acceptable->identifier->identifier );
//    const CSymbolTable::SymbolType identifierType = table->ResolveType( identifierSymbol );


}


void CTypeChecker::Visit( const CExpressionParamList *acceptable )
{
    assert( acceptable != nullptr );

    for( auto param : acceptable->children ) {
        param->Accept( this );
    }
}

void CTypeChecker::Visit( const CIntliteralExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->intliteral != nullptr );

    expressionTypes.push_back( intSymbol );
}

void CTypeChecker::Visit( const CTrueExpression *acceptable )
{
    assert( acceptable != nullptr );

    expressionTypes.push_back( booleanSymbol );
}

void CTypeChecker::Visit( const CFalseExpression *acceptable )
{
    assert( acceptable != nullptr );

    expressionTypes.push_back( booleanSymbol );
}

void CTypeChecker::Visit( const CIdentifierExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->identifier != nullptr );

    const CSymbol* name = CSymbol::GetIntern( acceptable->identifier->identifier );
    const CSymbolTable::SymbolType type = table->ResolveType( name );

    const CSymbol* exprType = nullptr;
    if( type == CSymbolTable::SymbolType::VARIABLE ) {
        const CVariableInfo* varInfo = table->TryResolveVariable( name );
        assert( varInfo != nullptr );
        exprType = varInfo->GetTypeName();
    } else if( type == CSymbolTable::SymbolType::CLASS ) {
        std::cerr << "Class name is not allowed." << std::endl;
    } else if( type == CSymbolTable::SymbolType::METHOD ) {
        std::cerr << "Method name is not allowed." << std::endl;
    }
    expressionTypes.push_back( exprType );
}

void CTypeChecker::Visit( const CThisExpression *acceptable )
{
    assert( acceptable != nullptr );

    expressionTypes.push_back( currentClass->GetName() );
}

void CTypeChecker::Visit( const CNewArrayExpression *acceptable )
{
    assert( acceptable!= nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    const CSymbol* expressionType = expressionTypes.back();
    expressionTypes.pop_back();

    const CSymbol* type = intArraySymbol;
    if( expressionType != nullptr ) {
        if( expressionType != intSymbol ) {
            std::cerr << "Array size must be integer." << std::endl;
            type = nullptr;
        }
    }
    expressionTypes.push_back( type );
}

void CTypeChecker::Visit( const CNewIdentifierExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->identifier != nullptr );

    const CSymbol* name = CSymbol::GetIntern( acceptable->identifier->identifier );
    const CSymbolTable::SymbolType type = table->ResolveType( name );

    const CSymbol* exprType = name;
    if( type == CSymbolTable::SymbolType::UNDECLARED ) {
        std::cerr << "Use of undeclared identifier" << std::endl;
        exprType = nullptr;
    } else if( type != CSymbolTable::SymbolType::CLASS ) {
        std::cerr << "Only classes support operator 'new'." << std::endl;
        exprType = nullptr;
    }
    expressionTypes.push_back( exprType );
}

void CTypeChecker::Visit( const CNotExpression *acceptable )
{
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    // тип выражения остается без изменений
}

void CTypeChecker::Visit( const CParensExpression *acceptable ) {
    assert( acceptable != nullptr );
    assert( acceptable->expression != nullptr );

    acceptable->expression->Accept( this );
    // тип выражения остается без изменений
}
