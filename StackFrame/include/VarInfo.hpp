#pragma once

#include "../../SymbolTable/include/VariableInfo.h"

class CVarInfo {
public:
    CVarInfo(const CVariableInfo* variableInfo);
    void SetOffset(int offset);
    int GetOffset() const;
    int GetSize() const;
private:
    const CSymbol* name;
    const CSymbol* typeName;
    int offset;
    int size;
    void* value;  //TODO
};