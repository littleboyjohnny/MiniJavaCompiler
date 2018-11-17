#pragma once

#include "../interfaces/IMainClass.h"
#include "../core/IVisitor.h"
#include "../interfaces/IStatementS.h"

#include "../core/TerminalIdentifier.hpp"

class CMainClass : public IMainClass {
public:
    CMainClass( const CTerminalIdentifier * const _className,
            const CTerminalIdentifier * const _argName,
            const IStatementS * const _statementS ) :
            className( _className ),
            argName( _argName ),
            statementS( _statementS )
    {}

    void Accept( const IVisitor * visitor ) const
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const className;
    const CTerminalIdentifier * const argName;
    const IStatementS * const statementS;
};


