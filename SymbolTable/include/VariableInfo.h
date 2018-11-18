#pragma once

#include "Info.h"
#include "Symbol.h"

#include <string>
#include <memory>

class CVariableInfo : IInfo {
public:
    CVariableInfo( const CSymbol* _name, const CSymbol* _typeName );


    inline const std::string& GetName() const
    {
        return name->GetString();
    }

    inline const std::string& GetTypeName() const
    {
        return typeName->GetString();
    }

private:
    const CSymbol* name;
    const CSymbol* typeName;
};