#pragma once

#include "Info.h"
#include "Symbol.h"
#include "VariableInfo.h"
#include "BlockScope.h"

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

class CMethodInfo : public IInfo {
public:
    CMethodInfo( const CSymbol* _name, const CSymbol* _retTypeName );

    CBlockScope* GetScope();

    void RegisterAsParameter( const CSymbol* symbol );
    bool TryRegisterAsParameter( const CSymbol* symbol );

    const CVariableInfo* TryResolveParameter( int paramIndex );
    const CVariableInfo* TryResolveParameter( const CSymbol* paramSymbol );

private:
    const CSymbol* name;
    const CSymbol* retTypeName;
    std::vector<const CSymbol*> parameters;

    std::unique_ptr<CBlockScope> scope;
};
