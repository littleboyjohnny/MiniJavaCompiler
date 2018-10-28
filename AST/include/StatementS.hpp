#ifndef MINIJAVACOMPILER_STATEMENTS_HPP
#define MINIJAVACOMPILER_STATEMENTS_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../interfaces/IVisitor.h"

class CStatementS : public IStatementS {
public:
    CStatementS( const IStatement * const _statement, const IStatementS * const _statementS ) :
        statement( _statement ),
        statementS( _statementS )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

private:
    const IStatement * const statement;
    const IStatementS * const statementS
};

#endif //MINIJAVACOMPILER_STATEMENTS_HPP
