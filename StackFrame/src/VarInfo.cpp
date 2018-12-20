// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/VarInfo.hpp"

CVarInfo::CVarInfo(const CVariableInfo *variableInfo) : name(variableInfo->GetName()), typeName(variableInfo->GetTypeName()) {
    offset = 0;
}