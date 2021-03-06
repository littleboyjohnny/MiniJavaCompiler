#pragma once

#include <memory>

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../core/IVisitor.h"

class CCurlyBraceStatement : public IStatement {
public:
    CCurlyBraceStatement( const IStatementS * const _statementS ) :
        statementS( _statementS )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IStatementS> statementS;
};


