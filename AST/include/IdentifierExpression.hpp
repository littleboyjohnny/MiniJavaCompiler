#ifndef MINIJAVACOMPILER_IDENTIFIEREXPRESSION_HPP
#define MINIJAVACOMPILER_IDENTIFIEREXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class IdentifierExpression : public IExpression
{
public:
    IdentifierExpression( const char* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const char* const identifier;
};

#endif //MINIJAVACOMPILER_IDENTIFIEREXPRESSION_HPP
