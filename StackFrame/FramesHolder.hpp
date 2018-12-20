#pragma once

#include "include/Frame.hpp"
#include "../SymbolTable/include/Symbol.h"

#include <map>

class CFramesHolder {
public:
    void AddFrame(const CSymbol* name, const IFrame* frame) {
        frames[name] = frame;
    }

    const IFrame* GetFrame( const CSymbol* name ) {
        auto it = frames.find( name );
        if (it == frames.end()) {
            return nullptr;
        }
        return it->second;
    }
private:
    std::map<const CSymbol*, const IFrame*> frames;
};