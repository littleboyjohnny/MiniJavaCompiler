#pragma once

#include "FrameInterface.h"
#include "InFrameAccess.h"
#include "VarInfo.hpp"
#include "../../SymbolTable/include/Symbol.h"
#include "../../SymbolTable/include/VariableInfo.h"

class CFrame : public IFrame {
public:
    CFrame();
    void AddFormal( const CVariableInfo* ) ;
    void AddLocal( const CSymbol* name ) ;
    int FormalsCount() const ;
    const IAccess* Formal( int index ) const ;
    const IAccess* FindLocalOfFormal( const CSymbol* name ) const ;
    void ExternalCall();
private:
    int formalsCount;
    int framePointer;
    int size;
    int returnValue;
    void* thisClass;  //TODO
    std::vector<const CSymbol*> arguments;
    std::map<const CSymbol*, CVarInfo*> symbolToInfo;
};