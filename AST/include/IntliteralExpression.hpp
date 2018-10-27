#ifndef MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
#define MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class IntliteralExpression : public IExpression
{
public:
    IntliteralExpression( const int _intliteral ) : intliteral( _intliteral ) {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const int intliteral;
};

#endif //MINIJAVACOMPILER_INTLITERALEXPRESSION_HPP
