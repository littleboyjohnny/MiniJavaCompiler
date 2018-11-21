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

    const CSymbol* GetName() const;
    const CSymbol* GetRetTypeName() const;
    CBlockScope* GetScope();
    const CBlockScope* GetScope() const;

    void RegisterAsParameter( const CSymbol* symbol );
    bool TryRegisterAsParameter( const CSymbol* symbol );

    const CVariableInfo* TryResolveParameter( int paramIndex ) const;
    const CVariableInfo* TryResolveParameter( const CSymbol* paramSymbol ) const;

private:
    const CSymbol* name;
    const CSymbol* retTypeName;
    std::vector<const CSymbol*> parameters;

    std::unique_ptr<CBlockScope> scope;
};
