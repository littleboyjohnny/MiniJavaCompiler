#ifndef COMPILERAST_IVISITOR_H
#define COMPILERAST_IVISITOR_H

class CAdditionalExpressionParam;
class CAdditionalExpressionParamS;
class CAdditionalParam;
class CAdditionalParamS;
class CAndExpression;
class CArrayAssignmentStatement;
class CBooleanType;
class CCurlyBraceStatement;
class CCustomType;
class CDotExpression;
class CExpressionParamS;
class CFalseExpression;
class CGoal;
class CIdentifierExpression;
class CIfElseStatement;
class CIntArrayType;
class CIntliteralExpression;
class CIntType;
class CLengthExpression;
class CLessExpression;
class CMinusExpression;
class CMultiplyExpression;
class CNewArrayExpression;
class CNewIdentifierExpression;
class CNotExpression;
class CParams;
class CParensExpression;
class CPlusExpression;
class CPrintlnStatement;
class CSquarebracketsExpression;
class CStatementS;
class CThisExpression;
class CTrueExpression;
class CVarAssignmentStatement;
class CWhileStatement;
class CClassDeclaration;
class CMainClass;
class CClassDeclarationS;
class CExtension;
class CVarDeclarationS;
class CVarDeclaration;
class CMethodDeclarationS;
class CMethodDeclaration;

class CTerminalIdentifier;
class CTerminalIntliteral;
class CTerminalAnd;
class CTerminalFalse;
class CTerminalLess;
class CTerminalMinus;
class CTerminalMultiply;
class CTerminalPlus;
class CTerminalThis;
class CTerminalTrue;

class IAcceptable;

class IVisitor {
public:
    virtual void Visit( const CAdditionalExpressionParam* const acceptable ) const = 0;
    virtual void Visit( const CAdditionalExpressionParamS* acceptable ) const = 0;
    virtual void Visit( const CAdditionalParam* acceptable ) const = 0;
    virtual void Visit( const CAdditionalParamS* acceptable ) const = 0;
    virtual void Visit( const CAndExpression* acceptable ) const = 0;
    virtual void Visit( const CArrayAssignmentStatement* acceptable ) const = 0;
    virtual void Visit( const CBooleanType* acceptable ) const = 0;
    virtual void Visit( const CClassDeclaration* acceptable ) const = 0;
    virtual void Visit( const CClassDeclarationS* acceptable ) const = 0;
    virtual void Visit( const CCurlyBraceStatement* acceptable ) const = 0;
    virtual void Visit( const CCustomType* acceptable ) const = 0;
    virtual void Visit( const CDotExpression* acceptable ) const = 0;
    virtual void Visit( const CExpressionParamS* acceptable ) const = 0;
    virtual void Visit( const CExtension* acceptable ) const = 0;
    virtual void Visit( const CFalseExpression* acceptable ) const = 0;
    virtual void Visit( const CGoal* acceptable ) const = 0;
    virtual void Visit( const CIdentifierExpression* acceptable ) const = 0;
    virtual void Visit( const CIfElseStatement* acceptable ) const = 0;
    virtual void Visit( const CIntArrayType* acceptable ) const = 0;
    virtual void Visit( const CIntliteralExpression* acceptable ) const = 0;
    virtual void Visit( const CIntType* acceptable ) const = 0;
    virtual void Visit( const CLengthExpression* acceptable ) const = 0;
    virtual void Visit( const CLessExpression* acceptable ) const = 0;
    virtual void Visit( const CMainClass* acceptable ) const = 0;
    virtual void Visit( const CMethodDeclaration* acceptable ) const = 0;
    virtual void Visit( const CMethodDeclarationS* acceptable ) const = 0;
    virtual void Visit( const CMinusExpression* acceptable ) const = 0;
    virtual void Visit( const CMultiplyExpression* acceptable ) const = 0;
    virtual void Visit( const CNewArrayExpression* acceptable ) const = 0;
    virtual void Visit( const CNewIdentifierExpression* acceptable ) const = 0;
    virtual void Visit( const CNotExpression* acceptable ) const = 0;
    virtual void Visit( const CParams* acceptable ) const = 0;
    virtual void Visit( const CParensExpression* acceptable ) const = 0;
    virtual void Visit( const CPlusExpression* acceptable ) const = 0;
    virtual void Visit( const CPrintlnStatement* acceptable ) const = 0;
    virtual void Visit( const CSquarebracketsExpression* acceptable ) const = 0;
    virtual void Visit( const CStatementS* acceptable ) const = 0;
    virtual void Visit( const CThisExpression* acceptable ) const = 0;
    virtual void Visit( const CTrueExpression* acceptable ) const = 0;
    virtual void Visit( const CVarAssignmentStatement* acceptable ) const = 0;
    virtual void Visit( const CVarDeclaration* acceptable ) const = 0;
    virtual void Visit( const CVarDeclarationS* acceptable ) const = 0;
    virtual void Visit( const CWhileStatement* acceptable ) const = 0;

    virtual void Visit( const CTerminalIdentifier* acceptable ) const = 0;
    virtual void Visit( const CTerminalIntliteral* acceptable ) const = 0;
    virtual void Visit( const CTerminalAnd* acceptable ) const = 0;
    virtual void Visit( const CTerminalFalse* acceptable ) const = 0;
    virtual void Visit( const CTerminalLess* acceptable ) const = 0;
    virtual void Visit( const CTerminalMinus* acceptable ) const = 0;
    virtual void Visit( const CTerminalMultiply* acceptable ) const = 0;
    virtual void Visit( const CTerminalPlus* acceptable ) const = 0;
    virtual void Visit( const CTerminalThis* acceptable ) const = 0;
    virtual void Visit( const CTerminalTrue* acceptable ) const = 0;

};

#endif