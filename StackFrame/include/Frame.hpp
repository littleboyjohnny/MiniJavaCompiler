#pragma once

#include "FrameInterface.h"
#include "InFrameAccess.h"
#include "include/Symbol.h"
#include "include/VariableInfo.h"
#include "include/Temp.h"


class CFrame : public IFrame {
private:
    const int wordSize = 4;
public:
    CFrame( const std::string& nameClass, const std::string& nameMethod );
    void AddFormal( const std::string& name ) override;
    void AddLocal( const std::string& name ) override;
    void AddToReg( const std::string& name ) override;
    int FormalsCount() const override;
    const IRTree::IExp* ExternalCall(const std::string& name, const IRTree::IExp* exp) const override;
    const IRTree::IExp* GetAccess( const std::string& name ) const override;
    const IRTree::CTemp* FP() const override;
    int WordSize() const override;
    const IRTree::CTemp* This() const override;

private:
    int formalsCount;
    int size;
    const IRTree::CTemp framePointer;
    const IRTree::CTemp returnValue;
    const IRTree::CTemp thisAddress;

    const std::string methodName;

    std::map<const CSymbol*, const IAccess*> hashAccess;
};