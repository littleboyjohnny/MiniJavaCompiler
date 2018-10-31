#ifndef MINIJAVACOMPILER_ASTBUILDER_H
#define MINIJAVACOMPILER_ASTBUILDER_H

#include "../interfaces/IVisitor.h"
#include "../interfaces/IClassDeclarationS.h"
#include "../interfaces/IVarDeclarationS.h"
#include "../interfaces/IMethodDeclarationS.h"
#include "../interfaces/IParams.h"
#include "../interfaces/IStatementS.h"
#include "../interfaces/IExpressionParamS.h"
#include <string>
#include <cstdio>
#include <list>

class CASTBuilder : public IVisitor {
public:
    CASTBuilder( const char * );
    ~CASTBuilder();
    void printEdge( const void *,const void * ) const;
    void addLabel( const void *, const char * ) const;
    void Visit( const CAdditionalExpressionParam* acceptable ) const;
    void Visit( const CAdditionalExpressionParamS* acceptable ) const;
    void Visit( const CAdditionalParam* acceptable ) const;
    void Visit( const CAdditionalParamS* acceptable ) const;
    void Visit( const CArrayAssignmentStatement* acceptable ) const;
    void Visit( const CBooleanType* acceptable ) const;
    void Visit( const CClassDeclaration* acceptable ) const;
    void Visit( const CClassDeclarationS* acceptable ) const;
    void Visit( const CCurlyBraceStatement* acceptable ) const;
    void Visit( const CCustomType* acceptable ) const;
    void Visit( const CCallExpression* acceptable ) const;
    void Visit( const CExpressionParamS* acceptable ) const;
    void Visit( const CExtension* acceptable ) const;
    void Visit( const CFalseExpression* acceptable ) const;
    void Visit( const CGoal* acceptable ) const;
    void Visit( const CIdentifierExpression* acceptable ) const;
    void Visit( const CIfElseStatement* acceptable ) const;
    void Visit( const CIntArrayType* acceptable ) const;
    void Visit( const CIntliteralExpression* acceptable ) const;
    void Visit( const CIntType* acceptable ) const;
    void Visit( const CLengthExpression* acceptable ) const;
    void Visit( const CMainClass* acceptable ) const;
    void Visit( const CMethodDeclaration* acceptable ) const;
    void Visit( const CMethodDeclarationS* acceptable ) const;
    void Visit( const CNewArrayExpression* acceptable ) const;
    void Visit( const CNewIdentifierExpression* acceptable ) const;
    void Visit( const CNotExpression* acceptable ) const;
    void Visit( const CParams* acceptable ) const;
    void Visit( const CParam* acceptable ) const;
    void Visit( const CParensExpression* acceptable ) const;
    void Visit( const CPrintlnStatement* acceptable ) const;
    void Visit( const CSquarebracketsExpression* acceptable ) const;
    void Visit( const CStatementS* acceptable ) const;
    void Visit( const CThisExpression* acceptable ) const;
    void Visit( const CTrueExpression* acceptable ) const;
    void Visit( const CVarAssignmentStatement* acceptable ) const;
    void Visit( const CVarDeclaration* acceptable ) const;
    void Visit( const CVarDeclarationS* acceptable ) const;
    void Visit( const CWhileStatement* acceptable ) const;
    void Visit( const CBinaryOpExpression* acceptable ) const;

    void Visit( const CTerminalIdentifier* acceptable ) const;
    void Visit( const CTerminalIntliteral* acceptable ) const;

private:
    FILE* file;
    mutable const IClassDeclarationS * headClassDeclarationS = nullptr;
    mutable const IVarDeclarationS * headVarDeclarationS = nullptr;
    mutable const IMethodDeclarationS * headMethodDeclarationS = nullptr;
    mutable const IParams * headParams = nullptr;
    mutable std::list< const IStatementS * > listHeadsStatements;
    mutable std::list< const IExpressionParamS * > listHeadsExpressionParams;
    //std::list<CAdditionalParam> listAdditionalParam;
};

#endif //MINIJAVACOMPILER_ASTBUILDER_H
