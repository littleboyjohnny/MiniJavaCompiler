#ifndef MINIJAVACOMPILER_FALSEEXPRESSION_HPP
#define MINIJAVACOMPILER_FALSEEXPRESSION_HPP

#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"

class CFalseExpression : public IExpression
{
public:
    CFalseExpression(){}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

};

#endif //MINIJAVACOMPILER_FALSEEXPRESSION_HPP
