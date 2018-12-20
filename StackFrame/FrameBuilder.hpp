// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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