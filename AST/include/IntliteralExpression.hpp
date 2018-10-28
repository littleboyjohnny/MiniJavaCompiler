#ifndef MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
#define MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

#include "../include/TerminalIntliteral.hpp"

class CIntliteralExpression : public IExpression
{
public:
    CIntliteralExpression( const CTerminalIntliteral* const _intliteral ) : intliteral( _intliteral ) {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIntliteral* const intliteral;
};

#endif //MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
