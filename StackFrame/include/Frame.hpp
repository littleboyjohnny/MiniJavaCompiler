// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

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
    int FormalsCount() const override;
    const IRTree::IExp* ExternalCall(const std::string& name, const IRTree::IExp* exp) const override;
    const IRTree::IExp* GetAccess( const std::string& name ) const override;
    const IRTree::CTemp* FP() const override;
    int WordSize() const override;
    const IRTree::CTemp* This() const override;

    const std::string& GetClassName() const override;
    const std::string& GetMethodName() const override;

private:
    void AddToFrame( const std::string& name );
    void AddToReg( const std::string& name );

private:
    int formalsCount;
    int size;
    const IRTree::CTemp framePointer;
    const IRTree::CTemp returnValue;
    const IRTree::CTemp thisAddress;

    const std::string methodName;
    const std::string className;

    std::map<const CSymbol*, const IAccess*> hashAccess;
};