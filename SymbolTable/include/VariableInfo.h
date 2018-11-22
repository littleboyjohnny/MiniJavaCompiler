#pragma once

#include "Info.h"
#include "Symbol.h"

#include <memory>

class CVariableInfo : IInfo {
public:
    CVariableInfo( const CSymbol* _name, const CSymbol* _typeName );

    const CSymbol* GetName() const;
    const CSymbol* GetTypeName() const;

private:
    const CSymbol* name;
    const CSymbol* typeName;
};