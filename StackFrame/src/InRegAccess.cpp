#include "include/InRegAccess.h"

#include "include/TempExp.hpp"

CInRegAccess::CInRegAccess( const IRTree::CTemp* _reg ) : reg( _reg ) {}

const IRTree::IExp* CInRegAccess::GetExp() const {
    return new IRTree::CTempExp( reg );
}
