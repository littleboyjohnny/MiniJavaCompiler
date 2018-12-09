#include "../include/Frame.hpp"

CFrame::CFrame() {
    formalsCount = 0;
}

void CFrame::AddFormal(const CVariableInfo* variableInfo) {
    formalsCount++;
    int offset = 0;
    if (arguments.size()) {
        auto prevArg = symbolToInfo[arguments.back()];
        offset = prevArg->GetOffset() + prevArg->GetSize();
    }
    const CSymbol* name = variableInfo->GetName();
    arguments.push_back(name);
    CInFrameAccess* inFrameAccess = new CInFrameAccess(variableInfo, offset);
    symbolToInfo[name] = inFrameAccess;
}

void CFrame::AddLocal(const CSymbol *name) {

}
