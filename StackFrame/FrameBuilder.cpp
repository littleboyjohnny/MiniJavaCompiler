// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "FrameBuilder.hpp"

const CFramesHolder* CFrameBuilder::build(const CSymbolTable *table) {
    auto classesNames = table->BackBlockScope()->GetClassNames();
    for (auto className : classesNames) {
        CClassInfo* classInfo = table->TryResolveClass( className );
        auto methodsNames = classInfo->GetScope()->GetMethodNames();
        for (auto methodName : methodsNames) {
            CMethodInfo* methodInfo = classInfo->GetScope()->TryResolveMethod( methodName );
            CX86MiniJavaFrame* newFrame = new CX86MiniJavaFrame();

            auto params = methodInfo->GetParameterNames();
            for (auto param : params) {
                CVariableInfo* variableInfo = methodInfo->TryResolveParameter(param);
                newFrame->AddFormal( variableInfo ) //TODO
            }

            framesHolder->AddFrame(newFrame);
        }
    }
}

const CFramesHolder* CFrameBuilder::getFramesHolder() const {
    return framesHolder;
}