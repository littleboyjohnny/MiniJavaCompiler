#ifndef MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP
#define MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"
#include "IdentifierExpression.hpp"

class NewIdentifierExpression : public IExpression
{
public:
    NewIdentifierExpression( const IdentifierExpression* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IdentifierExpression* const identifier;
};

#endif //MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP
