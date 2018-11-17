#pragma once

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../core/IVisitor.h"

class CStatementS : public IStatementS {
public:
    CStatementS( const IStatement * const _statement, const IStatementS * const _statementS ) :
        statement( _statement ),
        statementS( _statementS )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IStatement * const statement;
    const IStatementS * const statementS;
};


