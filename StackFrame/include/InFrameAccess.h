#pragma once

#include "Access.h"

class CInFrameAccess : public IAccess {
public:
    CInFrameAccess( const IRTree::CTemp* framePtr, int _offset );
    ~CInFrameAccess() final = default;
    const IRTree::IExp* GetExp() const override;
private:
    const IRTree::CTemp* framePtr;
    int offset;
};