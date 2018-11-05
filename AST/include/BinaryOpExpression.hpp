#ifndef MINIJAVACOMPILER_BINARYOPEXPRESSION_HPP
#define MINIJAVACOMPILER_BINARYOPEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

class CBinaryOpExpression : public IExpression {
public:
    enum OpType { PLUS = '+', MINUS = '-', MULTIPLY = '*', LESS = '<', AND = '&' };

public:
    CBinaryOpExpression( const IExpression* const _left,
                         OpType _opType,
                         const IExpression* const _right ) :
        left( _left ),
        opType( _opType ),
        right( _right )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IExpression* const left;
    const OpType opType;
    const IExpression* const right;
};

#endif //MINIJAVACOMPILER_BINARYOPEXPRESSION_HPP
