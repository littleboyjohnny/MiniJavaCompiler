#ifndef MINIJAVACOMPILER_ARRAYASSIGNMENTSTATEMENT_HPP
#define MINIJAVACOMPILER_ARRAYASSIGNMENTSTATEMENT_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IExpression.h"
#include "../interfaces/IVisitor.h"
#include "TerminalIdentifier.hpp"

class CArrayAssignmentStatement : public IStatement {
public:
    CArrayAssignmentStatement( const CTerminalIdentifier * const _arrayName,
                               const IExpression * const _indexExpression,
                               const IExpression * const _expression ) :
        arrayName( _arrayName ),
        indexExpression( _indexExpression ),
        expression( _expression )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const CTerminalIdentifier * const arrayName;
    const IExpression * const indexExpression;
    const IExpression * const expression;
};

#endif //MINIJAVACOMPILER_ARRAYASSIGNMENTSTATEMENT_HPP
