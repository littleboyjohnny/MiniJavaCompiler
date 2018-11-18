#pragma once

#include "Info.h"
#include "Symbol.h"
#include "VariableInfo.h"
#include "BlockScope.h"

#include <string>
#include <unordered_map>
#include <memory>

class CMethodInfo : public IInfo {
public:
    CMethodInfo( const CSymbol* _name, const CSymbol* _retTypeName );

    CBlockScope* GetScope();
    void SetScope( CBlockScope* _scope );

private:
    const CSymbol* name;
    const CSymbol* retTypeName;

    std::unique_ptr<CBlockScope> scope;
};