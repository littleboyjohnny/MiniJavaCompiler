#pragma once

#include "Info.h"
#include "Symbol.h"
#include "MethodInfo.h"
#include "VariableInfo.h"
#include "BlockScope.h"

#include <unordered_map>

class CClassInfo : public IInfo {
public:
    CClassInfo( const CSymbol* _name );

    CBlockScope* GetScope();
    void SetScope( CBlockScope* _scope );

private:
    const CSymbol* name;

    CBlockScope* scope;
};
