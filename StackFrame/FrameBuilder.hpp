#pragma once

#include "../SymbolTable/include/SymbolTable.h"
#include "include/Frame.hpp"
#include "FramesHolder.hpp"

#include <vector>

class CFrameBuilder {
public:
    CFrameBuilder();
    ~CFrameBuilder();

    const CFramesHolder* build( std::unique_ptr<CSymbolTable>& table );
    const CFramesHolder* getFramesHolder() const;
private:
    CFramesHolder* framesHolder;
};