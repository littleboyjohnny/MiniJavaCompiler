// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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