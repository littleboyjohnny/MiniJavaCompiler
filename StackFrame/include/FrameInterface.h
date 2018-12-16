#pragma once

#include <vector>

#include "../../SymbolTable/include/Symbol.h"
#include "Access.h"
#include "InRegAccess.h"
#include "include/VariableInfo.h"
#include "include/Temp.h"
#include "include/Exp.h"

class IFrame {
public:
    virtual void AddFormal( const CVariableInfo* ) = 0;
    virtual void AddLocal( const CSymbol* name ) = 0;
    virtual int FormalsCount() const = 0;
    virtual const IAccess* Formal( int index ) const  = 0;
    virtual const IAccess* FindLocalOfFormal( const CSymbol* name ) const  = 0;
    virtual void ExternalCall(const std::string& name, const IRTree::IExp* exp) = 0;
    virtual IRTree::IExp* GetAddress() const = 0;
    virtual const IRTree::CTemp* FP() const = 0;
    virtual int WordSize() const = 0;
};