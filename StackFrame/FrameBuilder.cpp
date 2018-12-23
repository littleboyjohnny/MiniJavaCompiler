// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "FrameBuilder.hpp"

CFrameBuilder::CFrameBuilder() {
    framesHolder = new CFramesHolder();
}

CFrameBuilder::~CFrameBuilder() {
    delete framesHolder;
}

const CFramesHolder* CFrameBuilder::build( std::unique_ptr<CSymbolTable>& table ) {
    auto classesNames = table->BackBlockScope()->GetClassNames();
    for (auto className : classesNames) {
        CClassInfo* classInfo = table->TryResolveClass( className );
        auto methodsNames = classInfo->GetScope()->GetMethodNames();
        for (auto methodName : methodsNames) {
            CMethodInfo* methodInfo = classInfo->GetScope()->TryResolveMethod( methodName );
            auto newFrame = new CFrame(className->GetString(), methodName->GetString());

            auto params = methodInfo->GetParameterNames();
            for (auto param : params) {
                newFrame->AddFormal( param->GetString() );
            }

            auto localsNames = methodInfo->GetScope()->GetVariableNames();
            for (auto local : localsNames) {
                newFrame->AddLocal( local->GetString() );
            }

            framesHolder->AddFrame( newFrame );
        }
    }
    return framesHolder;
}

const CFramesHolder* CFrameBuilder::getFramesHolder() const {
    return framesHolder;
}