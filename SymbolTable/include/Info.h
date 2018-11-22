#pragma once

#include <string>

class CSymbol;

class IInfo {
public:
    virtual const CSymbol* GetName() const = 0;
    virtual std::string GetStringRepresentation() const = 0;
};