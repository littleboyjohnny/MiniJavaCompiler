// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/InFrameAccess.h"
#include "include/MemExp.hpp"
#include "include/BinOpExp.hpp"
#include "include/TempExp.hpp"
#include "include/ConstExp.hpp"

CInFrameAccess::CInFrameAccess(const IRTree::CTemp* _framePtr, int _offset)
                        : framePtr( _framePtr ), offset( _offset ) {

}

const IRTree::IExp* CInFrameAccess::GetExp() const {
    return new IRTree::CMemExp(
                new IRTree::CBinOpExp(
                            IRTree::CBinOpExp::EBinOp::PLUS,
                            new IRTree::CTempExp( framePtr ),
                            new IRTree::CConstExp( offset )
                        )
            );
}