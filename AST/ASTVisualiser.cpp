// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <string>
#include <cstdio>

#include "ASTIncludes.h"
#include "ASTVisualiser.h"

CASTVisualiser::CASTVisualiser( const char * filename ) {
    file = fopen( filename, "w" );
    fprintf( file, "digraph AST {\n" );
}

CASTVisualiser::~CASTVisualiser() {
    fprintf( file, "}" );
    fclose( file );
}

void CASTVisualiser::addLabel( const void * pMemory, const char * label ) {
    fprintf( file, "\t%lld [label=\"%s\"];\n", (const long long)pMemory, label );
}

void CASTVisualiser::printEdge( const void * from, const void * to ) {
    fprintf( file, "\t%lld -> %lld;\n", (const long long)from, (const long long)to );
}

void CASTVisualiser::Visit( const CAdditionalExpressionParam* acceptable ) {

}

void CASTVisualiser::Visit( const CAdditionalExpressionParamS* acceptable ) {

}

void CASTVisualiser::Visit( const CAdditionalParam* acceptable ) {

}

void CASTVisualiser::Visit( const CAdditionalParamS* acceptable ) {

}

void CASTVisualiser::Visit( const CArrayAssignmentStatement* acceptable ) {
    if( acceptable->arrayName ) {
        printEdge( acceptable, acceptable->arrayName.get() );
        acceptable->arrayName->Accept( this );
    }
    if( acceptable->indexExpression) {
        printEdge( acceptable, acceptable->indexExpression.get() );
        acceptable->indexExpression->Accept( this );
    }
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "ArrayAssignmentStatement" );
}

void CASTVisualiser::Visit( const CClassDeclaration* acceptable ) {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className.get() );
        acceptable->className->Accept( this );
    }
    if( acceptable->extension ) {
        printEdge( acceptable, acceptable->extension.get() );
        acceptable->extension->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS.get() );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->methodDeclarationS ) {
        printEdge( acceptable, acceptable->methodDeclarationS.get() );
        acceptable->methodDeclarationS->Accept( this );
    }
    addLabel( acceptable, "ClassDeclaration" );
}

void CASTVisualiser::Visit( const CClassDeclarationS* acceptable ) {
    if( acceptable->classDeclarationS ) {
        printEdge(acceptable, acceptable->classDeclarationS.get() );
        acceptable->classDeclarationS->Accept( this );
    }
    if( acceptable->classDeclaration ) {
        printEdge( acceptable, acceptable->classDeclaration.get() );
        acceptable->classDeclaration->Accept( this );
    }
    addLabel( acceptable, "ClassDeclarationS" );
}

void CASTVisualiser::Visit( const CCurlyBraceStatement* acceptable ) {
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS.get() );
        acceptable->statementS->Accept( this );
    }
    addLabel( acceptable, "CurlyBraceStatement" );
}

void CASTVisualiser::Visit ( const CType* acceptable ) {
    addLabel( acceptable, acceptable->typeName.c_str() );
}

void CASTVisualiser::Visit( const CCallExpression* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier.get() );
        acceptable->identifier->Accept( this );
    }
    if( acceptable->expressionParamS ) {
        printEdge( acceptable, acceptable->expressionParamS.get() );
        acceptable->expressionParamS->Accept( this );
    }
    addLabel( acceptable, "DotExpression" );
}

void CASTVisualiser::Visit( const CExpressionParamS* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    if( acceptable->addittionalExpressionParamS ) {
        printEdge( acceptable, acceptable->addittionalExpressionParamS.get() );
        acceptable->addittionalExpressionParamS->Accept( this );
    }
    addLabel( acceptable, "ExpressionParamS" );
}

void CASTVisualiser::Visit( const CExtension* acceptable ) {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className.get() );
        acceptable->className->Accept( this );
    }
    addLabel( acceptable, "Extension" );
}

void CASTVisualiser::Visit( const CFalseExpression* acceptable ) {
    addLabel( acceptable, "false" );
}

void CASTVisualiser::Visit( const CGoal* acceptable ) {
    if( acceptable->mainClass ) {
        printEdge( acceptable, acceptable->mainClass.get() );
        acceptable->mainClass->Accept( this );
    }
    if( acceptable->classDeclarationS ) {
        printEdge( acceptable, acceptable->classDeclarationS.get() );
        acceptable->classDeclarationS->Accept( this );
    }
    addLabel( acceptable, "Goal" );
}

void CASTVisualiser::Visit( const CIdentifierExpression* acceptable ) {
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier.get() );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "IdentifierExpression" );
}

void CASTVisualiser::Visit( const CIfElseStatement* acceptable ) {
    if( acceptable->condition ) {
        printEdge( acceptable, acceptable->condition.get() );
        acceptable->condition->Accept( this );
    }
    if( acceptable->ifStatement ) {
        printEdge( acceptable, acceptable->ifStatement.get() );
        acceptable->ifStatement->Accept( this );
    }
    if( acceptable->elseStatement ) {
        printEdge( acceptable, acceptable->elseStatement.get() );
        acceptable->elseStatement->Accept( this );
    }
    addLabel( acceptable, "IfElseStatement" );
}

void CASTVisualiser::Visit( const CIntliteralExpression* acceptable ) {
    if( acceptable->intliteral ) {
        printEdge( acceptable, acceptable->intliteral.get() );
        acceptable->intliteral->Accept( this );
    }
    addLabel( acceptable, "IntliteralExpression" );
}

void CASTVisualiser::Visit( const CLengthExpression* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "LengthExpression" );
}

void CASTVisualiser::Visit( const CMainClass* acceptable ) {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className.get() );
        acceptable->className->Accept( this );
    }
    if( acceptable->argName ) {
        printEdge( acceptable, acceptable->argName.get() );
        acceptable->argName->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS.get() );
        acceptable->statementS->Accept( this );
    }
    addLabel( acceptable, "MainClass" );
}

void CASTVisualiser::Visit( const CMethodDeclaration* acceptable ) {
    if( acceptable->returnType ) {
        printEdge( acceptable, acceptable->returnType.get() );
        acceptable->returnType->Accept( this );
    }
    if( acceptable->methodIdentifier ) {
        printEdge( acceptable, acceptable->methodIdentifier.get() );
        acceptable->methodIdentifier->Accept( this );
    }
    if( acceptable->params ) {
        printEdge( acceptable, acceptable->params.get() );
        acceptable->params->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS.get() );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS.get() );
        acceptable->statementS->Accept( this );
    }
    if( acceptable->returnExpression ) {
        printEdge( acceptable, acceptable->returnExpression.get() );
        acceptable->returnExpression->Accept( this );
    }
    addLabel( acceptable, "MethodDeclaration" );
}

void CASTVisualiser::Visit( const CMethodDeclarationS* acceptable ) {
    if( acceptable->methodDeclarationS ) {
        printEdge( acceptable, acceptable->methodDeclarationS.get() );
        acceptable->methodDeclarationS->Accept( this );
    }
    if( acceptable->methodDeclaration ) {
        printEdge( acceptable, acceptable->methodDeclaration.get() );
        acceptable->methodDeclaration->Accept( this );
    }
    addLabel( acceptable, "MethodDeclarationS" );
}

void CASTVisualiser::Visit( const CNewArrayExpression* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "NewArrayExpression" );
}

void CASTVisualiser::Visit( const CNewIdentifierExpression* acceptable ) {
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier.get() );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "NewIdentifierExpression" );
}

void CASTVisualiser::Visit( const CNotExpression* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "NotExpression" );
}

void CASTVisualiser::Visit( const CParams* acceptable ) {
    if( acceptable->param ) {
        printEdge( acceptable, acceptable->param.get() );
        acceptable->param->Accept( this );
    }
    if( acceptable->additionalParamS ) {
        printEdge( acceptable, acceptable->additionalParamS.get() );
        acceptable->additionalParamS->Accept( this );
    }
    addLabel( acceptable, "Params" );
}

void CASTVisualiser::Visit( const CParam* acceptable ) {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type.get() );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier.get() );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "Param" );
}

void CASTVisualiser::Visit( const CParensExpression* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "ParensExpression" );
}

void CASTVisualiser::Visit( const CPrintlnStatement* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "PrintlnStatement" );
}

void CASTVisualiser::Visit( const CSquarebracketsExpression* acceptable ) {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    if( acceptable->squarebraketsExpression ) {
        printEdge( acceptable, acceptable->squarebraketsExpression.get() );
        acceptable->squarebraketsExpression->Accept( this );
    }
    addLabel( acceptable, "SquarebracketsExpression" );
}

void CASTVisualiser::Visit( const CStatementS* acceptable ) {
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement.get() );
        acceptable->statement->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS.get() );
        acceptable->statementS->Accept( this );
    }
    addLabel( acceptable, "StatementS" );
}

void CASTVisualiser::Visit( const CTerminalIdentifier* acceptable ) {
    addLabel( acceptable, acceptable->identifier );
}

void CASTVisualiser::Visit( const CTerminalIntliteral* acceptable ) {
    addLabel( acceptable, std::to_string( acceptable->intliteral ).c_str() );
}

void CASTVisualiser::Visit( const CThisExpression* acceptable ) {
    addLabel( acceptable, "this" );
}

void CASTVisualiser::Visit( const CTrueExpression* acceptable ) {
    addLabel( acceptable, "true" );
}

void CASTVisualiser::Visit( const CVarAssignmentStatement* acceptable ) {
    if( acceptable->varName ) {
        printEdge( acceptable, acceptable->varName.get() );
        acceptable->varName->Accept( this );
    }
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression.get() );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "VarAssignmentStatement" );
}

void CASTVisualiser::Visit( const CVarDeclaration* acceptable ) {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type.get() );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier.get() );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "VarDeclaration" );
}

void CASTVisualiser::Visit( const CVarDeclarationS* acceptable ) {
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS.get() );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->varDeclaration ) {
        printEdge( acceptable, acceptable->varDeclaration.get() );
        acceptable->varDeclaration->Accept( this );
    }
    addLabel( acceptable, "VarDeclarationS" );
}

void CASTVisualiser::Visit( const CWhileStatement* acceptable ) {
    if( acceptable->condition ) {
        printEdge( acceptable, acceptable->condition.get() );
        acceptable->condition->Accept( this );
    }
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement.get() );
        acceptable->statement->Accept( this );
    }
    addLabel( acceptable, "WhileStatement" );
}

void CASTVisualiser::Visit( const CBinaryOpExpression* acceptable ) {
    if( acceptable->left ) {
        printEdge( acceptable, acceptable->left.get() );
        acceptable->left->Accept( this );
    }
    char str[2] = { (char)acceptable->opType, '\0'};
    printEdge( acceptable, &acceptable->opType );
    addLabel( &acceptable->opType, str );
    if( acceptable->right ) {
        printEdge( acceptable, acceptable->right.get() );
        acceptable->right->Accept( this );
    }
    addLabel( acceptable, "BinaryOpExpression" );
}

void CASTVisualiser::Visit( const CClassDeclarationList * acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "ClassDeclarationList" );
}

void CASTVisualiser::Visit( const CVarDeclarationList * acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "VarDeclarationList" );
}

void CASTVisualiser::Visit( const CMethodDeclarationList * acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "MethodDeclarationList" );
}

void CASTVisualiser::Visit( const CParamList * acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "ParamList" );
}

void CASTVisualiser::Visit( const CStatementList * acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "StatementList" );
}

void CASTVisualiser::Visit( const CExpressionParamList * acceptable ) {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "ExpressionParamList" );
}