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

void CASTVisualiser::addLabel( const void * pMemory, const char * label ) const {
    fprintf( file, "\t%lld [label=\"%s\"];\n", (const long long)pMemory, label );
}

void CASTVisualiser::printEdge( const void * from, const void * to ) const {
    fprintf( file, "\t%lld -> %lld;\n", (const long long)from, (const long long)to );
}

void CASTVisualiser::Visit( const CAdditionalExpressionParam* acceptable ) const {

}

void CASTVisualiser::Visit( const CAdditionalExpressionParamS* acceptable ) const {

}

void CASTVisualiser::Visit( const CAdditionalParam* acceptable ) const {

}

void CASTVisualiser::Visit( const CAdditionalParamS* acceptable ) const {

}

void CASTVisualiser::Visit( const CArrayAssignmentStatement* acceptable ) const {
    if( acceptable->arrayName ) {
        printEdge( acceptable, acceptable->arrayName );
        acceptable->arrayName->Accept( this );
    }
    if( acceptable->indexExpression) {
        printEdge( acceptable, acceptable->indexExpression );
        acceptable->indexExpression->Accept( this );
    }
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "ArrayAssignmentStatement" );
}

void CASTVisualiser::Visit( const CBooleanType* acceptable ) const {
    addLabel( acceptable, "boolean" );
}

void CASTVisualiser::Visit( const CClassDeclaration* acceptable ) const {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className );
        acceptable->className->Accept( this );
    }
    if( acceptable->extension ) {
        printEdge( acceptable, acceptable->extension );
        acceptable->extension->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->methodDeclarationS ) {
        printEdge( acceptable, acceptable->methodDeclarationS );
        acceptable->methodDeclarationS->Accept( this );
    }
    addLabel( acceptable, "ClassDeclaration" );
}

void CASTVisualiser::Visit( const CClassDeclarationS* acceptable ) const {
    if( acceptable->classDeclarationS ) {
        printEdge(acceptable, acceptable->classDeclarationS );
        acceptable->classDeclarationS->Accept( this );
    }
    if( acceptable->classDeclaration ) {
        printEdge( acceptable, acceptable->classDeclaration );
        acceptable->classDeclaration->Accept( this );
    }
    addLabel( acceptable, "ClassDeclarationS" );
}

void CASTVisualiser::Visit( const CCurlyBraceStatement* acceptable ) const {
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
    addLabel( acceptable, "CurlyBraceStatement" );
}

void CASTVisualiser::Visit( const CCustomType* acceptable ) const {
    if( acceptable->typeName ) {
        printEdge( acceptable, acceptable->typeName );
        acceptable->typeName->Accept( this );
    }
    addLabel( acceptable, "CustomType" );
}

void CASTVisualiser::Visit( const CCallExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    if( acceptable->expressionParamS ) {
        printEdge( acceptable, acceptable->expressionParamS );
        acceptable->expressionParamS->Accept( this );
    }
    addLabel( acceptable, "DotExpression" );
}

void CASTVisualiser::Visit( const CExpressionParamS* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    if( acceptable->addittionalExpressionParamS ) {
        printEdge( acceptable, acceptable->addittionalExpressionParamS );
        acceptable->addittionalExpressionParamS->Accept( this );
    }
    addLabel( acceptable, "ExpressionParamS" );
}

void CASTVisualiser::Visit( const CExtension* acceptable ) const {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className );
        acceptable->className->Accept( this );
    }
    addLabel( acceptable, "Extension" );
}

void CASTVisualiser::Visit( const CFalseExpression* acceptable ) const {
    addLabel( acceptable, "false" );
}

void CASTVisualiser::Visit( const CGoal* acceptable ) const {
    if( acceptable->mainClass ) {
        printEdge( acceptable, acceptable->mainClass );
        acceptable->mainClass->Accept( this );
    }
    if( acceptable->classDeclarationS ) {
        printEdge( acceptable, acceptable->classDeclarationS );
        acceptable->classDeclarationS->Accept( this );
    }
    addLabel( acceptable, "Goal" );
}

void CASTVisualiser::Visit( const CIdentifierExpression* acceptable ) const {
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "IdentifierExpression" );
}

void CASTVisualiser::Visit( const CIfElseStatement* acceptable ) const {
    if( acceptable->condition ) {
        printEdge( acceptable, acceptable->condition );
        acceptable->condition->Accept( this );
    }
    if( acceptable->ifStatement ) {
        printEdge( acceptable, acceptable->ifStatement );
        acceptable->ifStatement->Accept( this );
    }
    if( acceptable->elseStatement ) {
        printEdge( acceptable, acceptable->elseStatement );
        acceptable->elseStatement->Accept( this );
    }
    addLabel( acceptable, "IfElseStatement" );
}

void CASTVisualiser::Visit( const CIntArrayType* acceptable ) const {
    addLabel( acceptable, "int[]" );
}

void CASTVisualiser::Visit( const CIntliteralExpression* acceptable ) const {
    if( acceptable->intliteral ) {
        printEdge( acceptable, acceptable->intliteral );
        acceptable->intliteral->Accept( this );
    }
    addLabel( acceptable, "IntliteralExpression" );
}

void CASTVisualiser::Visit( const CIntType* acceptable ) const {
    addLabel( acceptable, "int" );
}

void CASTVisualiser::Visit( const CLengthExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "LengthExpression" );
}

void CASTVisualiser::Visit( const CMainClass* acceptable ) const {
    if( acceptable->className ) {
        printEdge( acceptable, acceptable->className );
        acceptable->className->Accept( this );
    }
    if( acceptable->argName ) {
        printEdge( acceptable, acceptable->argName );
        acceptable->argName->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
    addLabel( acceptable, "MainClass" );
}

void CASTVisualiser::Visit( const CMethodDeclaration* acceptable ) const {
    if( acceptable->returnType ) {
        printEdge( acceptable, acceptable->returnType );
        acceptable->returnType->Accept( this );
    }
    if( acceptable->methodIdentifier ) {
        printEdge( acceptable, acceptable->methodIdentifier );
        acceptable->methodIdentifier->Accept( this );
    }
    if( acceptable->params ) {
        printEdge( acceptable, acceptable->params );
        acceptable->params->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
    if( acceptable->returnExpression ) {
        printEdge( acceptable, acceptable->returnExpression );
        acceptable->returnExpression->Accept( this );
    }
    addLabel( acceptable, "MethodDeclaration" );
}

void CASTVisualiser::Visit( const CMethodDeclarationS* acceptable ) const {
    if( acceptable->methodDeclarationS ) {
        printEdge( acceptable, acceptable->methodDeclarationS );
        acceptable->methodDeclarationS->Accept( this );
    }
    if( acceptable->methodDeclaration ) {
        printEdge( acceptable, acceptable->methodDeclaration );
        acceptable->methodDeclaration->Accept( this );
    }
    addLabel( acceptable, "MethodDeclarationS" );
}

void CASTVisualiser::Visit( const CNewArrayExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "NewArrayExpression" );
}

void CASTVisualiser::Visit( const CNewIdentifierExpression* acceptable ) const {
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "NewIdentifierExpression" );
}

void CASTVisualiser::Visit( const CNotExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "NotExpression" );
}

void CASTVisualiser::Visit( const CParams* acceptable ) const {
    if( acceptable->param ) {
        printEdge( acceptable, acceptable->param );
        acceptable->param->Accept( this );
    }
    if( acceptable->additionalParamS ) {
        printEdge( acceptable, acceptable->additionalParamS );
        acceptable->additionalParamS->Accept( this );
    }
    addLabel( acceptable, "Params" );
}

void CASTVisualiser::Visit( const CParam* acceptable ) const {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "Param" );
}

void CASTVisualiser::Visit( const CParensExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "ParensExpression" );
}

void CASTVisualiser::Visit( const CPrintlnStatement* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "PrintlnStatement" );
}

void CASTVisualiser::Visit( const CSquarebracketsExpression* acceptable ) const {
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    if( acceptable->squarebraketsExpression ) {
        printEdge( acceptable, acceptable->squarebraketsExpression );
        acceptable->squarebraketsExpression->Accept( this );
    }
    addLabel( acceptable, "SquarebracketsExpression" );
}

void CASTVisualiser::Visit( const CStatementS* acceptable ) const {
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement );
        acceptable->statement->Accept( this );
    }
    if( acceptable->statementS ) {
        printEdge( acceptable, acceptable->statementS );
        acceptable->statementS->Accept( this );
    }
    addLabel( acceptable, "StatementS" );
}

void CASTVisualiser::Visit( const CTerminalIdentifier* acceptable ) const {
    addLabel( acceptable, acceptable->identifier );
}

void CASTVisualiser::Visit( const CTerminalIntliteral* acceptable ) const {
    addLabel( acceptable, std::to_string( acceptable->intliteral ).c_str() );
}

void CASTVisualiser::Visit( const CThisExpression* acceptable ) const {
    addLabel( acceptable, "this" );
}

void CASTVisualiser::Visit( const CTrueExpression* acceptable ) const {
    addLabel( acceptable, "true" );
}

void CASTVisualiser::Visit( const CVarAssignmentStatement* acceptable ) const {
    if( acceptable->varName ) {
        printEdge( acceptable, acceptable->varName );
        acceptable->varName->Accept( this );
    }
    if( acceptable->expression ) {
        printEdge( acceptable, acceptable->expression );
        acceptable->expression->Accept( this );
    }
    addLabel( acceptable, "VarAssignmentStatement" );
}

void CASTVisualiser::Visit( const CVarDeclaration* acceptable ) const {
    if( acceptable->type ) {
        printEdge( acceptable, acceptable->type );
        acceptable->type->Accept( this );
    }
    if( acceptable->identifier ) {
        printEdge( acceptable, acceptable->identifier );
        acceptable->identifier->Accept( this );
    }
    addLabel( acceptable, "VarDeclaration" );
}

void CASTVisualiser::Visit( const CVarDeclarationS* acceptable ) const {
    if( acceptable->varDeclarationS ) {
        printEdge( acceptable, acceptable->varDeclarationS );
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->varDeclaration ) {
        printEdge(acceptable, acceptable->varDeclaration);
        acceptable->varDeclaration->Accept(this);
    }
    addLabel( acceptable, "VarDeclarationS" );
}

void CASTVisualiser::Visit( const CWhileStatement* acceptable ) const {
    if( acceptable->condition ) {
        printEdge( acceptable, acceptable->condition );
        acceptable->condition->Accept( this );
    }
    if( acceptable->statement ) {
        printEdge( acceptable, acceptable->statement );
        acceptable->statement->Accept( this );
    }
    addLabel( acceptable, "WhileStatement" );
}

void CASTVisualiser::Visit( const CBinaryOpExpression* acceptable ) const {
    if( acceptable->left ) {
        printEdge( acceptable, acceptable->left );
        acceptable->left->Accept( this );
    }
    char str[2] = { (char)acceptable->opType, '\0'};
    printEdge( acceptable, &acceptable->opType );
    addLabel( &acceptable->opType, str );
    if( acceptable->right ) {
        printEdge( acceptable, acceptable->right );
        acceptable->right->Accept( this );
    }
    addLabel( acceptable, "BinaryOpExpression" );
}

void CASTVisualiser::Visit( const CClassDeclarationList * acceptable ) const {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "ClassDeclarationList" );
}

void CASTVisualiser::Visit( const CVarDeclarationList * acceptable ) const {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "VarDeclarationList" );
}

void CASTVisualiser::Visit( const CMethodDeclarationList * acceptable ) const {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "MethodDeclarationList" );
}

void CASTVisualiser::Visit( const CParamList * acceptable ) const {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "ParamList" );
}

void CASTVisualiser::Visit( const CStatementList * acceptable ) const {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "StatementList" );
}

void CASTVisualiser::Visit( const CExpressionParamList * acceptable ) const {
    for( int i = 0; i < acceptable->children.size(); i++ ) {
        printEdge( acceptable, acceptable->children[i] );
        acceptable->children[i]->Accept( this );
    }
    addLabel( acceptable, "ExpressionParamList" );
}