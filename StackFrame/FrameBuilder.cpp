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

            /*TODO(LittleBoyJohnny, Issue): здесь получаем также аргументы функции
             * и поэтому расположение остальных переменных на стеке съезжает,
             * а также перезаписываются аргументы, обработанные выше
             */
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