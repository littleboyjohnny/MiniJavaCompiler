#include "../include/Frame.hpp"
#include "include/CallExp.hpp"
#include "include/NameExp.hpp"
#include "include/ExpList.hpp"

CFrame::CFrame( const std::string& nameClass, const std::string& nameMethod )
    : framePointer(nameClass + "::" + nameMethod)
    , thisAddress(nameClass + "::" + nameMethod + "::this")
    , returnValue(nameClass + "::" + nameMethod + "::return")
    , methodName( nameMethod )
    {
    AddToReg( framePointer.getName() );
    AddToReg( returnValue.getName() );
    AddToReg( thisAddress.getName() );
    size += wordSize;
}

void CFrame::AddFormal(const std::string& name) {
    formalsCount++;
    hashAccess[new CSymbol(name)] = new CInFrameAccess(&framePointer, size);
    size += wordSize;
}

void CFrame::AddLocal(const std::string& name) {
    hashAccess[new CSymbol(name)] = new CInFrameAccess(&framePointer, size);
    size += wordSize;
}

void CFrame::AddToReg(const std::string &name) {
    hashAccess[new CSymbol(name)] = new CInRegAccess(
                                        new IRTree::CTemp(
                                                    "Reg::" + framePointer.getName() + "::" + name
                                        )
                                    );
}

const IRTree::IExp* CFrame::ExternalCall(const std::string &name, const IRTree::IExp *exp) const {
    return new IRTree::CCallExp(
                new IRTree::CNameExp( new IRTree::CLabel( methodName ) ),
                new IRTree::CExpList( exp )
            );
}

const IRTree::IExp* CFrame::GetAccess( const std::string& name ) const {
    const CSymbol* acc = new CSymbol(name);
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