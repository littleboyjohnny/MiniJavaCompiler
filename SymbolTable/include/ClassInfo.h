#pragma once

#include "Info.h"
#include "Symbol.h"
#include "MethodInfo.h"
#include "VariableInfo.h"
#include "BlockScope.h"

#include <unordered_map>
#include <memory>

class CClassInfo : public IInfo {
public:
    explicit CClassInfo( const CSymbol* _name );

    const CSymbol* GetName() const;
    std::string GetStringRepresentation() const;
    CBlockScope* GetScope();
    const CBlockScope* GetScope() const;

private:
    const CSymbol* name;

    std::unique_ptr<CBlockScope> scope;
};
