#ifndef MINIJAVACOMPILER_CURLYBRACESTATEMENT_HPP
#define MINIJAVACOMPILER_CURLYBRACESTATEMENT_HPP

#include "../interfaces/IStatement.h"
#include "../interfaces/IStatementS.h"
#include "../interfaces/IVisitor.h"

class CCurlyBraceStatement : public IStatement {
public:
    CCurlyBraceStatement( const IStatementS * const _statementS ) :
        statementS( _statementS )
    {}

    void Accept( const IVisitor* visitor ) const
    {
        visitor->Visit( this );
    }

    const IStatementS * const statementS;
};

#endif //MINIJAVACOMPILER_CURLYBRACESTATEMENT_HPP
