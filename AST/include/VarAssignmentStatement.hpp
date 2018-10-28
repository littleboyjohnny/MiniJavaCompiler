#ifndef MINIJAVACOMPILER_VARASSIGNMENTSTATEMENT_HPP
#define MINIJAVACOMPILER_VARASSIGNMENTSTATEMENT_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "IdentifierExpression.hpp"

class CVarAssignmentStatement : public IStatement {
public:
    CVarAssignmentStatement( const CIdentifierExpression * const _varName,
                             const IExpression * const _expression ) :
        varName( _varName ),
        expression( _expression )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const CIdentifierExpression * const varName;
    const IExpression * const expression;
};

#endif //MINIJAVACOMPILER_VARASSIGNMENTSTATEMENT_HPP
