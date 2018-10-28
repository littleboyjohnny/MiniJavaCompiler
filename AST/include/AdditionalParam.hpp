#ifndef MINIJAVACOMPILER_ADDITIONALPARAM_HPP
#define MINIJAVACOMPILER_ADDITIONALPARAM_HPP

#include "../interfaces/IAdditionalParam.h"
#include "../interfaces/IType.h"
#include "../interfaces/IVisitor.h"
#include "TerminalIdentifier.hpp"

class CAdditionalParam : public IAdditionalParam {
public:
    CAdditionalParam( const IType * const _type, const CTerminalIdentifier * const _identifier ) :
        type( _type ),
        identifier( _identifier )
    {}

    void Accept( IVisitor* visitor )
    {
        visitor->Visit( this );
    }

    const IType * const type;
    const CTerminalIdentifier * const identifier;
};

#endif //MINIJAVACOMPILER_ADDITIONALPARAM_HPP
