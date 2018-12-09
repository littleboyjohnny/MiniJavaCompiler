#include "../include/VarInfo.hpp"

CVarInfo::CVarInfo(const CVariableInfo *variableInfo) : name(variableInfo->GetName()), typeName(variableInfo->GetTypeName()) {
    offset = 0;
}