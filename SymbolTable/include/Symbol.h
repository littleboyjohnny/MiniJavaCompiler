#pragma once

#include <string>
#include <unordered_map>

class CSymbol {

public:
    explicit CSymbol( const std::string& _str );
    CSymbol( const CSymbol& ) = delete;


    const std::string& GetString() const;

    static const CSymbol* GetIntern( const std::string& src );

    void operator=( const CSymbol& ) = delete;

private:
    const std::string str;
};