#pragma once

#include "include/Frame.hpp"
#include "../SymbolTable/include/Symbol.h"

#include <map>
#include <cassert>

class CFramesHolder {
public:
    void AddFrame(const IFrame* frame) {
        assert( frame != nullptr );
        std::string s = "FRAME::" + frame->GetClassName() + "::" + frame->GetMethodName();
        const CSymbol* ident = CSymbol::GetIntern( s );
        frames[ ident ] = frame;
    }

    const IFrame* GetFrame( const std::string& nameClass, const std::string& nameMethod ) const {
        std::string localName = "FRAME::" + nameClass + "::" + nameMethod;
        auto it = frames.find( CSymbol::GetIntern( localName ) );
        if (it == frames.end()) {
            return nullptr;
        }
        return it->second;
    }
private:
    std::map<const CSymbol*, const IFrame*> frames;
};