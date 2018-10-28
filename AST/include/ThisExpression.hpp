#ifndef MINIJAVACOMPILER_THISEXPRESSION_HPP
#define MINIJAVACOMPILER_THISEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CThisExpression : public IExpression
{
public:
    CThisExpression(){}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_THISEXPRESSION_HPP
