#ifndef MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP
#define MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"
#include "TerminalIdentifier.hpp"

class CNewIdentifierExpression : public IExpression
{
public:
    CNewIdentifierExpression( const CTerminalIdentifier* const _identifier ) : identifier( _identifier ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier* const identifier;
};

#endif //MINIJAVACOMPILER_NEWIDENTIFIEREXPRESSION_HPP
