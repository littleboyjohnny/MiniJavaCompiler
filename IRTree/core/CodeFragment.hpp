#pragma once

#include "include/Frame.hpp"
#include "include/Stm.h"

struct CCodeFragment {
    const CFrame* Frame;
    const IRTree::IStm* Body;
    const CCodeFragment* Next;

    CCodeFragment( const CFrame* frame, const IRTree::IStm* body, const CCodeFragment* next )
                    : Frame( frame ), Body( body ), Next( next )
                    {}
};