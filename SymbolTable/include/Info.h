#pragma once

class CSymbol;

class IInfo {
public:
    virtual const CSymbol* GetName() const = 0;
};