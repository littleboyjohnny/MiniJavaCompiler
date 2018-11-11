#include "gtest/gtest.h"
#include "../lexer/lexer.h"
#include "../build/lex.yy.cpp"
#include "TokenMap.cpp"
#include "../parser/parser.cpp"

#include <fstream>
#include <iostream>
#include <string>

TokenMap* tokenMap = new TokenMap();
std::string pathToInputs = "../tests/inputs/";
std::string pathToKeys = "../tests/LexerTestsFiles/correct/";

void testLexerBySample( std::string samplefname, std::string keyfname ) {
    std::string pathToSample = pathToInputs + samplefname;
    std::string pathToKey = pathToKeys + keyfname;

    yyin = fopen( pathToSample.c_str(), "r" );

    std::ifstream fin( pathToKey.c_str(), std::ifstream::in );
    if ( !fin.is_open() )
        printf( "File with keys can not be opened\n" );

    std::string token;
    int tokenId = 0;
    while( std::getline( fin, token ) ) {
        tokenId = yylex();
        if ( tokenId ) {
            ASSERT_EQ( tokenMap->idToToken[tokenId], token );
        } else {
            FAIL() << "Not enough tokens\n";
        }
    }
    if ( yylex() ) {
        FAIL() << "Too many tokens\n";
    }

    fclose( yyin );
    fin.close();
}

TEST( LexerTests, sample1 ) {
    testLexerBySample( "sample1.java", "sample1" );
}
