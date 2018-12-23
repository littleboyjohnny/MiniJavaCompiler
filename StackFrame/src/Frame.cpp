// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/Frame.hpp"
#include "include/CallExp.hpp"
#include "include/NameExp.hpp"
#include "include/ExpList.hpp"

CFrame::CFrame( const std::string& nameClass, const std::string& nameMethod )
    : framePointer(nameClass + "::" + nameMethod + "::FP")
    , thisAddress(nameClass + "::" + nameMethod + "::this")
    , returnValue(nameClass + "::" + nameMethod + "::return")
    , methodName( nameMethod )
    , className( nameClass ) {

    AddToReg( "FP" );
    AddToReg( "return" );
    AddToReg( "this" );

    size += wordSize;
}

void CFrame::AddToFrame( const std::string& name ) {
    std::string ident = className + "::" + methodName + "::" + name;
    hashAccess[ CSymbol::GetIntern( ident ) ] = new CInFrameAccess(&framePointer, size);
    size += wordSize;
}

void CFrame::AddFormal(const std::string& name) {
    formalsCount++;
    AddToFrame( name );
}

void CFrame::AddLocal(const std::string& name) {
    AddToFrame( name );
}

void CFrame::AddToReg(const std::string &name) {
    std::string ident = className + "::" + methodName + "::" + name;
    hashAccess[ CSymbol::GetIntern( ident ) ] = new CInRegAccess(
                                        new IRTree::CTemp(
                                                className + "::" + methodName + "::" + name
                                        )
                                    );
}

const IRTree::IExp* CFrame::ExternalCall(const std::string &name, const IRTree::IExp *exp) const {
    return new IRTree::CCallExp(
                new IRTree::CNameExp( IRTree::CLabel( name ) ),
                new IRTree::CExpList( exp )
            );
}

const IRTree::IExp* CFrame::GetAccess( const std::string& name ) const {
    std::string ident = className + "::" + methodName + "::" + name;
    const CSymbol* acc = CSymbol::GetIntern( ident );
    auto it = hashAccess.find( acc );
    if ( it != hashAccess.end() ) {
        return it->second->GetExp();
    }
    return nullptr;
}

int CFrame::FormalsCount() const {
    return formalsCount;
}

const IRTree::CTemp* CFrame::FP() const {
    return &framePointer;
}

int CFrame::WordSize() const {
    return wordSize;
}

const IRTree::CTemp* CFrame::This() const {
    return &thisAddress;
}

const std::string& CFrame::GetClassName() const {
    return className;
}

const std::string& CFrame::GetMethodName() const {
    return methodName;
}