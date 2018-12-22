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
    virtual void AddFormal( const std::string& name ) = 0;
    virtual void AddLocal( const std::string& name ) = 0;
    virtual int FormalsCount() const = 0;
    virtual const IRTree::IExp* ExternalCall(const std::string& name, const IRTree::IExp* exp) const = 0;
    virtual const IRTree::IExp* GetAccess( const std::string& name ) const = 0;
    virtual const IRTree::CTemp* FP() const = 0;
    virtual const IRTree::CTemp* This() const = 0;
    virtual int WordSize() const = 0;

    virtual const std::string& GetClassName() const = 0;
    virtual const std::string& GetMethodName() const = 0;
};