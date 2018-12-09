#pragma once

#include "../SymbolTable/include/SymbolTable.h"
#include "include/X86MiniJavaFrame.h"
#include "FramesHolder.hpp"

#include <vector>

class CFrameBuilder {
public:
    const CFramesHolder* build(const CSymbolTable* table);
    const CFramesHolder* getFramesHolder() const;
private:
    CFramesHolder* framesHolder;
};