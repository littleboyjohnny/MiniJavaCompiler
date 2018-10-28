#ifndef MINIJAVACOMPILER_IDENTIFIEREXPRESSION_HPP
#define MINIJAVACOMPILER_IDENTIFIEREXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

#include "../include/TerminalIdentifier.hpp"

class CIdentifierExpression : public IExpression
{
public:
    CIdentifierExpression( const CTerminalIdentifier * const _identifier ) : identifier( _identifier ) {}

    void Accept( const IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const identifier;
};

#endif //MINIJAVACOMPILER_IDENTIFIEREXPRESSION_HPP
