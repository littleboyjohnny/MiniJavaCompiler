#ifndef MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
#define MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

#include "../include/TerminalIntliteral.hpp"

class CIntliteralExpression : public IExpression
{
public:
    CIntliteralExpression( const CTerminalIntliteral* const _intliteral ) : intliteral( _intliteral ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const CTerminalIntliteral* const intliteral;
};

#endif //MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
