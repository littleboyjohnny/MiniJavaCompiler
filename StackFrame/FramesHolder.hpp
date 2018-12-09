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