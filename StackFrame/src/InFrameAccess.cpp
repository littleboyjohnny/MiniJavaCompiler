// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/InFrameAccess.h"

CInFrameAccess::CInFrameAccess(const CVariableInfo *_variableInfo, int _offset)
                        : variableInfo(_variableInfo), offset(_offset) {

}
