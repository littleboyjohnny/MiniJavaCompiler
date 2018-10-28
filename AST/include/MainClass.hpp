#ifndef MINIJAVACOMPILER_MAINCLASS_HPP
#define MINIJAVACOMPILER_MAINCLASS_HPP

#include "../interfaces/IMainClass.h"
#include "../interfaces/IVisitor.h"
#include "../interfaces/IStatementS.h"

#include "../include/TerminalIdentifier.hpp"

class CMainClass : public IMainClass {
public:
    CMainClass( const CTerminalIdentifier * const _className,
            const CTerminalIdentifier * const _argName,
            const IStatementS * const _statementS ) :
            className( _className ),
            argName( _argName ),
            statementS( _statementS )
    {}

    void Accept( const IVisitor * visitor )
    {
        visitor->Visit( this );
    }

    const CTerminalIdentifier * const className;
    const CTerminalIdentifier * const argName;
    const IStatementS * const statementS;
};

#endif //MINIJAVACOMPILER_MAINCLASS_HPP
