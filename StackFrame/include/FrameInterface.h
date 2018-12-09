#pragma once

#include <vector>

#include "../../SymbolTable/include/Symbol.h"
#include "Access.h"
#include "InRegAccess.h"

class IFrame {
public:
    virtual void AddFormal( const CVariableInfo* ) = 0;
    virtual void AddLocal( const CSymbol* name ) = 0;
    virtual int FormalsCount() const = 0;
    virtual const IAccess* Formal( int index ) const  = 0;
    virtual const IAccess* FindLocalOfFormal( const CSymbol* name ) const  = 0;
    virtual void ExternalCall() = 0;
};