#pragma once

#include <memory>

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

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IExpression> left;
    const OpType opType;
    const std::unique_ptr<const IExpression> right;
};


