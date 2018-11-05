#include <string>
#include <list>
#include <vector>

#include "ASTBuilder.h"
#include "ASTIncludes.h"

CASTBuilder::CASTBuilder() {

}

CASTBuilder::~CASTBuilder() {

}

const CGoal* CASTBuilder::BuildAST(const CGoal * goal) {
    goal->Accept( this );
    ast = static_cast<const CGoal *>(child);
    return ast;
}

void CASTBuilder::Visit( const CAdditionalExpressionParam* acceptable ) const {
    const IExpression * expression = nullptr;

    if(acceptable->expression) {
        acceptable->expression->Accept(this);
        expression = static_cast<const IExpression *> ( child );
        listHeadsExpressionParams.back()->children.push_back( expression );
    }

    child = expression;
}

void CASTBuilder::Visit( const CAdditionalExpressionParamS* acceptable ) const {
    if (acceptable->additionalExpressionParamS) {
        acceptable->additionalExpressionParamS->Accept(this);
    }
    if (acceptable->additionalExpressionParam) {
        acceptable->additionalExpressionParam->Accept(this);
    }
}

void CASTBuilder::Visit( const CAdditionalParam* acceptable ) const {
    const IParam * param = nullptr;

    if (acceptable->param) {
        acceptable->param->Accept(this);
        param = static_cast<const IParam *> ( child );
        headParams->children.push_back( param );
    }
}

void CASTBuilder::Visit( const CAdditionalParamS* acceptable ) const {
    if (acceptable->additionalParamS) {
        acceptable->additionalParamS->Accept(this);
    }
    if (acceptable->additionalParam) {
        acceptable->additionalParam->Accept(this);
    }
}

void CASTBuilder::Visit( const CArrayAssignmentStatement* acceptable ) const {
    const CArrayAssignmentStatement * arrayAssignmentStatement = nullptr;
    const CTerminalIdentifier * arrayName = nullptr;
    const IExpression * indexExpression = nullptr;
    const IExpression * expression = nullptr;

    if (acceptable->arrayName) {
        acceptable->arrayName->Accept(this);
        arrayName = static_cast<const CTerminalIdentifier *> ( child );
    }
    if (acceptable->indexExpression) {
        acceptable->indexExpression->Accept(this);
        indexExpression = static_cast<const IExpression *> ( child );
    }
    if (acceptable->expression) {
        acceptable->expression->Accept(this);
        expression = static_cast<const IExpression *> ( child );
    }

    arrayAssignmentStatement = new CArrayAssignmentStatement(arrayName, indexExpression, expression);
    child = arrayAssignmentStatement;
}

void CASTBuilder::Visit( const CBooleanType* acceptable ) const {
    const CBooleanType * booleanType = new CBooleanType();
    child = booleanType;
}

void CASTBuilder::Visit( const CClassDeclaration* acceptable ) const {
    const CClassDeclaration * classDeclaration = nullptr;
    const CTerminalIdentifier * className = nullptr;
    const IExtension * extension = nullptr;
    const CVarDeclarationList * varDeclarationList = nullptr;
    const CMethodDeclarationList * methodDeclarationList = nullptr;

    if (acceptable->className) {
        acceptable->className->Accept(this);
        className = static_cast<const CTerminalIdentifier *> ( child );
    }
    if (acceptable->extension) {
        acceptable->extension->Accept(this);
        extension = static_cast<const IExtension *> ( child );
    }
    if (acceptable->varDeclarationS) {
        varDeclarationList = new CVarDeclarationList();
        headVarDeclarationS = varDeclarationList;
        acceptable->varDeclarationS->Accept(this);
    }
    if (acceptable->methodDeclarationS) {
        methodDeclarationList = new CMethodDeclarationList();
        headMethodDeclarationS = methodDeclarationList;
        acceptable->methodDeclarationS->Accept(this);
    }
    classDeclaration = new CClassDeclaration(className, extension, varDeclarationList, methodDeclarationList);
    child = classDeclaration;
}

void CASTBuilder::Visit( const CClassDeclarationS* acceptable ) const {
    const IClassDeclaration * classDeclaration = nullptr;

    if (acceptable->classDeclarationS) {
        acceptable->classDeclarationS->Accept(this);
    }
    if (acceptable->classDeclaration) {
        acceptable->classDeclaration->Accept(this);
        classDeclaration = static_cast<const IClassDeclaration *> ( child );
        headClassDeclarationS->children.push_back( classDeclaration );
    }
    child = classDeclaration;
}

void CASTBuilder::Visit( const CCurlyBraceStatement* acceptable ) const {
    const CCurlyBraceStatement * curlyBraceStatement = nullptr;
    const CStatementList * statementList = nullptr;

    if (acceptable->statementS) {
        statementList = new CStatementList();
        listHeadsStatements.push_back(statementList);
        acceptable->statementS->Accept(this);
        listHeadsStatements.pop_back();
    }

    curlyBraceStatement = new CCurlyBraceStatement(statementList);
    child = curlyBraceStatement;
}

void CASTBuilder::Visit( const CCustomType* acceptable ) const {
    const CCustomType * customType = nullptr;
    const CTerminalIdentifier * typeName = nullptr;

    if (acceptable->typeName) {
        acceptable->typeName->Accept(this);
        typeName = static_cast<const CTerminalIdentifier *> ( child );
    }

    customType = new CCustomType(typeName);
    child = customType;
}

void CASTBuilder::Visit( const CCallExpression* acceptable ) const {
    const CCallExpression * callExpression = nullptr;
    const IExpression * expression = nullptr;
    const CTerminalIdentifier * identifier = nullptr;
    const CExpressionParamList * expressionParamList = nullptr;

    if (acceptable->expression) {
        acceptable->expression->Accept(this);
        expression = static_cast<const IExpression *> ( child );
    }
    if (acceptable->identifier) {
        acceptable->identifier->Accept(this);
        identifier = static_cast<const CTerminalIdentifier *> ( child );
    }
    if (acceptable->expressionParamS) {
        expressionParamList = new CExpressionParamList();
        listHeadsExpressionParams.push_back(expressionParamList);
        acceptable->expressionParamS->Accept(this);
        listHeadsExpressionParams.pop_back();
    }

    callExpression = new CCallExpression(expression, identifier, expressionParamList);
    child = callExpression;
}

void CASTBuilder::Visit( const CExpressionParamS* acceptable ) const {
    const IExpression * expression = nullptr;

    if (acceptable->expression) {
        acceptable->expression->Accept(this);
        expression = static_cast<const IExpression *> ( child );
        listHeadsExpressionParams.back()->children.push_back( expression );
    }
    if (acceptable->addittionalExpressionParamS) {
        acceptable->addittionalExpressionParamS->Accept(this);
    }

    child = expression;
}

void CASTBuilder::Visit( const CExtension* acceptable ) const {
    const CExtension * extension = nullptr;
    const CTerminalIdentifier * className = nullptr;

    if (acceptable->className) {
        acceptable->className->Accept(this);
        className = static_cast<const CTerminalIdentifier *> ( child );
    }

    extension = new CExtension(className);
    child = extension;
}

void CASTBuilder::Visit( const CFalseExpression * acceptable ) const {
    const CFalseExpression * falseExpression = new CFalseExpression();
    child = falseExpression;
}

void CASTBuilder::Visit( const CGoal * acceptable ) const {
    const CGoal * goal = nullptr;
    const IMainClass * mainClass = nullptr;
    const CClassDeclarationList * classDeclarationList = nullptr;

    if ( acceptable->mainClass ) {
        acceptable->mainClass->Accept( this );
        mainClass = static_cast<const IMainClass *> ( child );
    }
    if ( acceptable->classDeclarationS ) {
        classDeclarationList = new CClassDeclarationList();
        headClassDeclarationS = classDeclarationList;
        acceptable->classDeclarationS->Accept( this );
    }

    goal = new CGoal( mainClass, classDeclarationList );
    child = goal;
}

void CASTBuilder::Visit( const CIdentifierExpression* acceptable ) const {
    const CIdentifierExpression * identifierExpression = nullptr;
    const CTerminalIdentifier * identifier = nullptr;

    if (acceptable->identifier) {
        acceptable->identifier->Accept(this);
        identifier = static_cast<const CTerminalIdentifier *> ( child );
    }

    identifierExpression = new CIdentifierExpression( identifier );
    child = identifierExpression;
}

void CASTBuilder::Visit( const CIfElseStatement* acceptable ) const {
    const CIfElseStatement * ifElseStatement = nullptr;
    const IExpression * condition = nullptr;
    const IStatement * ifStatement = nullptr;
    const IStatement * elseStatement = nullptr;

    if (acceptable->condition) {
        acceptable->condition->Accept(this);
        condition = static_cast<const IExpression *> ( child );
    }
    if (acceptable->ifStatement) {
        acceptable->ifStatement->Accept(this);
        ifStatement = static_cast<const IStatement *> ( child );
    }
    if (acceptable->elseStatement) {
        acceptable->elseStatement->Accept(this);
        elseStatement = static_cast<const IStatement *> ( child );
    }

    ifElseStatement = new CIfElseStatement(condition, ifStatement, elseStatement);
    child = ifElseStatement;
}

void CASTBuilder::Visit( const CIntArrayType* acceptable ) const {
    const CIntArrayType * intArrayType = new CIntArrayType();
    child = intArrayType;
}

void CASTBuilder::Visit( const CIntliteralExpression* acceptable ) const {
    const CIntliteralExpression * intliteralExpression = nullptr;
    const CTerminalIntliteral * intliteral = nullptr;

    if (acceptable->intliteral) {
        acceptable->intliteral->Accept(this);
        intliteral = static_cast<const CTerminalIntliteral *> ( child );
    }
    intliteralExpression = new CIntliteralExpression( intliteral );
    child = intliteralExpression;
}

void CASTBuilder::Visit( const CIntType* acceptable ) const {
    const CIntType * intType = new CIntType();
    child = intType;
}

void CASTBuilder::Visit( const CLengthExpression* acceptable ) const {
    const CLengthExpression * lengthExpression = nullptr;
    const IExpression * expression = nullptr;

    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }

    lengthExpression= new CLengthExpression(expression);
    child = lengthExpression;
}

void CASTBuilder::Visit( const CMainClass* acceptable ) const {
    const CMainClass * mainClass = nullptr;
    const CTerminalIdentifier * className = nullptr;
    const CTerminalIdentifier * argName = nullptr;
    const CStatementList * statementList = nullptr;

    if( acceptable->className ) {
        acceptable->className->Accept( this );
        className = static_cast<const CTerminalIdentifier *> ( child );
    }
    if( acceptable->argName ) {
        acceptable->argName->Accept( this );
        argName = static_cast<const CTerminalIdentifier *> ( child );
    }
    if( acceptable->statementS ) {
        statementList = new CStatementList();
        listHeadsStatements.push_back(statementList);
        acceptable->statementS->Accept( this );
        listHeadsStatements.pop_back();
    }
    mainClass = new CMainClass(className, argName, statementList);
    child = mainClass;
}

void CASTBuilder::Visit( const CMethodDeclaration* acceptable ) const {
    const CMethodDeclaration * methodDeclaration = nullptr;
    const IType * returnType = nullptr;
    const CTerminalIdentifier * methodIdentifier = nullptr;
    const CParamList * paramList = nullptr;
    const CVarDeclarationList * varDeclarationList = nullptr;
    const CStatementList * statementList = nullptr;
    const IExpression * returnExpression = nullptr;

    if( acceptable->returnType ) {
        acceptable->returnType->Accept( this );
        returnType = static_cast<const IType *> ( child );
    }
    if( acceptable->methodIdentifier ) {
        acceptable->methodIdentifier->Accept( this );
        methodIdentifier = static_cast<const CTerminalIdentifier *> ( child );
    }
    if( acceptable->params ) {
        paramList = new CParamList();
        headParams = paramList;
        acceptable->params->Accept( this );
    }
    if( acceptable->varDeclarationS ) {
        varDeclarationList = new CVarDeclarationList();
        headVarDeclarationS = varDeclarationList;
        acceptable->varDeclarationS->Accept( this );
    }
    if( acceptable->statementS ) {
        statementList = new CStatementList();
        listHeadsStatements.push_back(statementList);
        acceptable->statementS->Accept( this );
        listHeadsStatements.pop_back();
    }
    if( acceptable->returnExpression ) {
        acceptable->returnExpression->Accept( this );
        returnExpression = static_cast<const IExpression *> ( child );
    }

    methodDeclaration = new CMethodDeclaration(returnType, methodIdentifier,
            paramList, varDeclarationList, statementList, returnExpression);
    child = methodDeclaration;
}

void CASTBuilder::Visit( const CMethodDeclarationS* acceptable ) const {
    const IMethodDeclaration * methodDeclaration = nullptr;

    if (acceptable->methodDeclarationS) {
        acceptable->methodDeclarationS->Accept(this);
    }
    if (acceptable->methodDeclaration) {
        acceptable->methodDeclaration->Accept(this);
        methodDeclaration = static_cast<const IMethodDeclaration *> ( child );
        headMethodDeclarationS->children.push_back(methodDeclaration);
    }

    child = methodDeclaration;
}

void CASTBuilder::Visit( const CNewArrayExpression* acceptable ) const {
    const CNewArrayExpression * newArrayExpression = nullptr;
    const IExpression * expression = nullptr;

    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }

    newArrayExpression = new CNewArrayExpression( expression );
    child = newArrayExpression;
}

void CASTBuilder::Visit( const CNewIdentifierExpression* acceptable ) const {
    const CNewIdentifierExpression * newIdentifierExpression = nullptr;
    const CTerminalIdentifier * identifier = nullptr;

    if( acceptable->identifier ) {
        acceptable->identifier->Accept( this );
        identifier = static_cast<const CTerminalIdentifier *> ( child );
    }

    newIdentifierExpression = new CNewIdentifierExpression( identifier );
    child = newIdentifierExpression;
}

void CASTBuilder::Visit( const CNotExpression* acceptable ) const {
    const CNotExpression * notExpression = nullptr;
    const IExpression * expression = nullptr;

    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }

    notExpression = new CNotExpression( expression );
    child = notExpression;
}

void CASTBuilder::Visit( const CParams* acceptable ) const {
    const IParam * param = nullptr;

    if( acceptable->param ) {
        acceptable->param->Accept( this );
        param = static_cast<const IParam *> ( child );
        headParams->children.push_back( param );
    }
    if( acceptable->additionalParamS ) {
        acceptable->additionalParamS->Accept( this );
    }

    child = param;
}

void CASTBuilder::Visit( const CParam* acceptable ) const {
    const CParam * param = nullptr;
    const IType * type = nullptr;
    const CTerminalIdentifier * identifier = nullptr;

    if( acceptable->type ) {
        acceptable->type->Accept( this );
        type = static_cast<const IType *> ( child );
    }
    if( acceptable->identifier ) {
        acceptable->identifier->Accept( this );
        identifier = static_cast<const CTerminalIdentifier *> ( child );
    }

    param = new CParam(type, identifier);
    child = param;
}

void CASTBuilder::Visit( const CParensExpression* acceptable ) const {
    const CParensExpression * parensExpression = nullptr;
    const IExpression * expression = nullptr;

    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }

    parensExpression = new CParensExpression( expression );
    child = parensExpression;
}

void CASTBuilder::Visit( const CPrintlnStatement* acceptable ) const {
    const CPrintlnStatement * printlnStatement = nullptr;
    const IExpression * expression = nullptr;

    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }

    printlnStatement = new CPrintlnStatement(expression);
    child = printlnStatement;
}

void CASTBuilder::Visit( const CSquarebracketsExpression* acceptable ) const {
    const CSquarebracketsExpression * squarebracketsExpression = nullptr;
    const IExpression * expression = nullptr;
    const IExpression * expressionInBrackets = nullptr;

    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }
    if( acceptable->squarebraketsExpression ) {
        acceptable->squarebraketsExpression->Accept( this );
        expressionInBrackets = static_cast<const IExpression *> ( child );
    }

    squarebracketsExpression = new CSquarebracketsExpression(expression, expressionInBrackets);
    child = squarebracketsExpression;
}

void CASTBuilder::Visit( const CStatementS* acceptable ) const {
    const IStatement * statement = nullptr;

    if( acceptable->statement ) {
        acceptable->statement->Accept( this );
        statement = static_cast<const IStatement *> ( child );
        listHeadsStatements.back()->children.push_back( statement );
    }
    if( acceptable->statementS ) {
        acceptable->statementS->Accept( this );
    }

    child = statement;
}

void CASTBuilder::Visit( const CTerminalIdentifier* acceptable ) const {
    const CTerminalIdentifier * terminalIdentifier = new CTerminalIdentifier(*acceptable);
    child = terminalIdentifier;
}

void CASTBuilder::Visit( const CTerminalIntliteral* acceptable ) const {
    const CTerminalIntliteral * terminalIntliteral = new CTerminalIntliteral(*acceptable);
    child = terminalIntliteral;
}

void CASTBuilder::Visit( const CThisExpression* acceptable ) const {
    const CThisExpression * thisExpression = new CThisExpression();
    child = thisExpression;
}

void CASTBuilder::Visit( const CTrueExpression* acceptable ) const {
    const CTrueExpression * trueExpression = new CTrueExpression();
    child = trueExpression;
}

void CASTBuilder::Visit( const CVarAssignmentStatement* acceptable ) const {
    const CVarAssignmentStatement * varAssignmentStatement = nullptr;
    const CTerminalIdentifier * varName = nullptr;
    const IExpression * expression = nullptr;

    if( acceptable->varName ) {
        acceptable->varName->Accept( this );
        varName = static_cast<const CTerminalIdentifier *> ( child );
    }
    if( acceptable->expression ) {
        acceptable->expression->Accept( this );
        expression = static_cast<const IExpression *> ( child );
    }

    varAssignmentStatement = new CVarAssignmentStatement(varName, expression);
    child = varAssignmentStatement;
}

void CASTBuilder::Visit( const CVarDeclaration* acceptable ) const {
    const CVarDeclaration * varDeclaration = nullptr;
    const IType * type = nullptr;
    const CTerminalIdentifier * identifier = nullptr;

    if( acceptable->type ) {
        acceptable->type->Accept( this );
        type = static_cast<const IType *> ( child );
    }
    if( acceptable->identifier ) {
        acceptable->identifier->Accept( this );
        identifier = static_cast<const CTerminalIdentifier *> ( child );
    }

    varDeclaration = new CVarDeclaration(type, identifier);
    child = varDeclaration;
}

void CASTBuilder::Visit( const CVarDeclarationS* acceptable ) const {
    const IVarDeclaration * varDeclaration = nullptr;

    if (acceptable->varDeclarationS) {
        acceptable->varDeclarationS->Accept(this);
    }
    if (acceptable->varDeclaration) {
        acceptable->varDeclaration->Accept(this);
        varDeclaration = static_cast<const IVarDeclaration *> ( child );
        headVarDeclarationS->children.push_back( varDeclaration );
    }

    child = varDeclaration;
}

void CASTBuilder::Visit( const CWhileStatement* acceptable ) const {
    const CWhileStatement * whileStatement = nullptr;
    const IExpression * condition = nullptr;
    const IStatement * statement = nullptr;

    if( acceptable->condition ) {
        acceptable->condition->Accept( this );
        condition = static_cast<const IExpression *> ( child );
    }
    if( acceptable->statement ) {
        acceptable->statement->Accept( this );
        statement = static_cast<const IStatement *> ( child );
    }

    whileStatement = new CWhileStatement(condition, statement);
    child = whileStatement;
}

void CASTBuilder::Visit( const CBinaryOpExpression* acceptable ) const {
    const CBinaryOpExpression * binaryOpExpression = nullptr;
    const IExpression * left = nullptr;
    const IExpression * right = nullptr;

    if( acceptable->left ) {
        acceptable->left->Accept( this );
        left = static_cast<const IExpression *> ( child );
    }
    if( acceptable->right ) {
        acceptable->right->Accept( this );
        right = static_cast<const IExpression *> ( child );
    }

    binaryOpExpression = new CBinaryOpExpression(left, acceptable->opType, right);
    child = binaryOpExpression;
}

void CASTBuilder::Visit( const CClassDeclarationList * acceptable ) const {

}

void CASTBuilder::Visit( const CExpressionParamList * acceptable ) const {

}

void CASTBuilder::Visit( const CMethodDeclarationList * acceptable ) const {

}

void CASTBuilder::Visit( const CParamList * acceptable ) const {

}

void CASTBuilder::Visit( const CStatementList * acceptable ) const {

}

void CASTBuilder::Visit( const CVarDeclarationList * acceptable ) const {

}