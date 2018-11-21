#include "gtest/gtest.h"
#include "../lexer/lexer.h"
#include "TokenMap.hpp"
#include "../parser/parser.cpp"

#include <fstream>
#include <iostream>
#include <string>

TokenMap* tokenMap = new TokenMap();
std::string pathToInputs = "../tests/inputs/";
std::string pathToKeys = "../tests/LexerTestsFiles/correct/";
std::string pathToResults = "../tests/LexerTestsFiles/results/";

void testLexerBySample( std::string samplefname, std::string keyfname, std::string resultfname ) {
    std::string pathToSample = pathToInputs + samplefname;
    std::string pathToKey = pathToKeys + keyfname;
    std::string pathToResult = pathToResults + resultfname;

    yyin = fopen( pathToSample.c_str(), "r" );

    std::ofstream fout( pathToResult.c_str(), std::ifstream::out );
    if ( !fout.is_open() )
        printf( "Output file with result can not be opened\n" );

    std::string token;
    int tokenId = 0;
    while( tokenId = yylex() ) {
        fout << tokenMap->idToToken[tokenId];
        if ( tokenMap->idToToken[tokenId] == "IDENTIFIER" ) {
            fout << " " << yylval.terminalIdentifier->identifier;
        } else if ( tokenMap->idToToken[tokenId] == "INTLITERAL" ) {
            fout << " " << yylval.terminalIntliteral->intliteral;
        }
        fout  << "\n";
    }
    fout.close();

    std::ifstream fresult( pathToResult.c_str(), std::ifstream::in );
    if ( !fresult.is_open() )
        printf( "File with results can not be opened\n" );
    std::string resultLine;
    std::ifstream fkeys( pathToKey.c_str(), std::ifstream::in );
    if ( !fkeys.is_open() )
        printf( "File with keys can not be opened\n" );
    std::string keyLine;
    while( std::getline( fresult, resultLine ) && std::getline( fkeys, keyLine )) {
        ASSERT_EQ( resultLine, keyLine );
    }
    if (std::getline( fresult, resultLine )) {
        FAIL() << "Too many tokens\n";
    }
    if (std::getline( fkeys, keyLine )) {
        FAIL() << "Not enough tokens\n";
    }
    fresult.close();
    fkeys.close();
}

TEST( LexerTests, sample1 ) {
    testLexerBySample( "sample1.java", "sample1", "sample1" );
}

TEST( LexerTests, BinarySearch ) {
    testLexerBySample( "BinarySearch.java", "BinarySearch", "BinarySearch" );
}

TEST( LexerTests, BinaryTree ) {
    testLexerBySample( "BinaryTree.java", "BinaryTree", "BinaryTree" );
}

TEST( LexerTests, BubbleSort ) {
    testLexerBySample( "BubbleSort.java", "BubbleSort", "BubbleSort" );
}

TEST( LexerTests, Factorial ) {
    testLexerBySample( "Factorial.java", "Factorial", "Factorial" );
}

TEST( LexerTests, LinearSearch ) {
    testLexerBySample( "LinearSearch.java", "LinearSearch", "LinearSearch" );
}

TEST( LexerTests, LinkedList ) {
    testLexerBySample( "LinkedList.java", "LinkedList", "LinkedList" );
}

TEST( LexerTests, QuickSort ) {
    testLexerBySample( "QuickSort.java", "QuickSort", "QuickSort" );
}

TEST( LexerTests, TreeVisitor ) {
    testLexerBySample( "TreeVisitor.java", "TreeVisitor", "TreeVisitor" );
}