#ifndef MINIJAVACOMPILER_WHILESTATEMENT_HPP
#define MINIJAVACOMPILER_WHILESTATEMENT_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CWhileStatement : public IStatement {
public:
    CWhileStatement( const IExpression * const _condition, const IStatement * const _statement ) :
        condition( _condition ),
        statement( _statement )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IExpression * const condition;
    const IStatement * const statement;
};

#endif //MINIJAVACOMPILER_WHILESTATEMENT_HPP
