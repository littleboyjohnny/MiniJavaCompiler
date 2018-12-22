#pragma once

#include "Access.h"
#include "include/Temp.h"

class CInRegAccess : public IAccess {
public:
    explicit CInRegAccess( const IRTree::CTemp* _reg );
    ~CInRegAccess() final = default;
    const IRTree::IExp* GetExp() const override;

private:
    const IRTree::CTemp* reg;
};