#ifndef MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP
#define MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"
#include "IdentifierExpression.hpp"

class CNewIdentifierExpression : public IExpression
{
public:
    CNewIdentifierExpression( const CIdentifierExpression* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const CIdentifierExpression* const identifier;
};

#endif //MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP
