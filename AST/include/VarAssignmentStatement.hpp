#ifndef MINIJAVACOMPILER_VARASSIGNMENTSTATEMENT_HPP
#define MINIJAVACOMPILER_VARASSIGNMENTSTATEMENT_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "TerminalIdentifier.hpp"

class CVarAssignmentStatement : public IStatement {
public:
    CVarAssignmentStatement( const CTerminalIdentifier * const _varName,
                             const IExpression * const _expression ) :
        varName( _varName ),
        expression( _expression )
    {}

    void Accept( const IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const varName;
    const IExpression * const expression;
};

#endif //MINIJAVACOMPILER_VARASSIGNMENTSTATEMENT_HPP
