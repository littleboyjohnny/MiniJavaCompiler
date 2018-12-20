// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once

#include "include/X86MiniJavaFrame.h"
#include "../SymbolTable/include/Symbol.h"

#include <map>

class CFramesHolder {
public:
    void AddFrame(CX86MiniJavaFrame* frame);
private:
    std::map<const CSymbol*, CX86MiniJavaFrame*> frames;
};