#ifndef MINIJAVACOMPILER_PRINTLNSTATEMENT_HPP
#define MINIJAVACOMPILER_PRINTLNSTATEMENT_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IStatement.h"

class CPrintlnStatement : public IStatement {
public:
    CPrintlnStatement( const IExpression * const _expression ) :
        expression( _expression )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression * const expression;
};

#endif //MINIJAVACOMPILER_PRINTLNSTATEMENT_HPP
