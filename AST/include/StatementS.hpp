// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include <memory>

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../core/IVisitor.h"

class CStatementS : public IStatementS {
public:
    CStatementS( const IStatement * const _statement, const IStatementS * const _statementS ) :
        statement( _statement ),
        statementS( _statementS )
    {}

    void Accept( IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const std::unique_ptr<const IStatement > statement;
    const std::unique_ptr<const IStatementS > statementS;
};


