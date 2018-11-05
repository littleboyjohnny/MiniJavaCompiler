#ifndef MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
#define MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../core/IVisitor.h"

#include "../core/TerminalIntliteral.hpp"

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
