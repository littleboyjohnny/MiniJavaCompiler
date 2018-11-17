#pragma once
#include <string>
#include <unordered_map>

class CSymbol {

public:

    CSymbol( const std::string& _str );
    CSymbol( const CSymbol& ) = delete;


    const std::string& String() const;
    void operator=( const CSymbol& ) = delete;
    static CSymbol* getIntern( const std::string& src );

private:
    const std::string str;
};