#pragma once

#include "Info.h"
#include "Symbol.h"

#include <string>
#include <memory>

class CVariableInfo : IInfo {
public:
    CVariableInfo( const CSymbol* _name, const CSymbol* _typeName );

    const std::string& GetName() const;
    const std::string& GetTypeName() const;

private:
    const CSymbol* name;
    const CSymbol* typeName;
};