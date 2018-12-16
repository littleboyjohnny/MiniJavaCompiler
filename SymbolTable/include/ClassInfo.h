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
    const CSymbol* GetParent() const;
    std::string GetStringRepresentation() const;
    CBlockScope* GetScope();
    const CBlockScope* GetScope() const;

    void SetParentName( const CSymbol *_parentName );
    void SetParent( const CClassInfo* _parent );

    int GetSize() const;

private:
    const CSymbol* name;
    const CSymbol* parentName;

    const CClassInfo* parent;

    std::unique_ptr<CBlockScope> scope;
};
