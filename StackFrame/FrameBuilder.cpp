#include "FrameBuilder.hpp"

const CFramesHolder* CFrameBuilder::build(const CSymbolTable *table) {
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

            framesHolder->AddFrame(new CSymbol(className->GetString() + "::" + methodName->GetString()), newFrame);
        }
    }
}

const CFramesHolder* CFrameBuilder::getFramesHolder() const {
    return framesHolder;
}