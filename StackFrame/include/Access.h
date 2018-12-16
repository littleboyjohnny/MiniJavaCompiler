#pragma once

class IAccess {
    virtual ~IAccess() {}
    const IRTree::IExp* GetExp( const IRTree::CTemp* framePtr ) const = 0;
};