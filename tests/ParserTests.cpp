#define PARSER_DEBUG 1

#include "gtest/gtest.h"
#include "../parser/parser.h"
#include "ParserTestYYLEX.hpp"

#include <fstream>
#include <string>
#include <stdio.h>
#include <memory>

std::string pathToInputs = "../tests/LexerTestsFiles/correct/";
std::string pathToKeys = "../tests/ParserTestsFiles/correct/";
std::string pathToResults = "../tests/ParserTestsFiles/results/";

void testParserBySample( std::string samplefname, std::string keyfname, std::string resultfname )
{
    std::string pathToResult = pathToResults + resultfname;
    std::string pathToSample = pathToInputs + samplefname;
    std::string pathToKey = pathToKeys + keyfname;

    FILE* toResults = fopen( pathToResult.c_str(), "w");
    if (toResults == NULL)
        printf("File can not be opened\n");

    Builder builder( pathToSample.c_str() );
    IAcceptable * goal = nullptr;
    yyparse( goal, toResults );
    std::unique_ptr<IAcceptable> p( goal );

    fclose(toResults);

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
        FAIL() << "Too many rules\n";
    }
    if (std::getline( fkeys, keyLine )) {
        FAIL() << "Not enough rules\n";
    }
    fresult.close();
    fkeys.close();
}

TEST( ParserTests, sample1 )
{
    testParserBySample( "sample1", "sample1", "sample1" );
}

TEST( ParserTests, BinarySearch ) {
    testParserBySample( "BinarySearch", "BinarySearch", "BinarySearch" );
}

TEST( ParserTests, BinaryTree ) {
    testParserBySample( "BinaryTree", "BinaryTree", "BinaryTree" );
}

TEST( ParserTests, BubbleSort ) {
    testParserBySample( "BubbleSort", "BubbleSort", "BubbleSort" );
}

TEST( ParserTests, Factorial ) {
    testParserBySample( "Factorial", "Factorial", "Factorial" );
}

TEST( ParserTests, LinearSearch ) {
    testParserBySample( "LinearSearch", "LinearSearch", "LinearSearch" );
}

TEST( ParserTests, LinkedList ) {
    testParserBySample( "LinkedList", "LinkedList", "LinkedList" );
}

TEST( ParserTests, QuickSort ) {
    testParserBySample( "QuickSort", "QuickSort", "QuickSort" );
}

TEST( ParserTests, TreeVisitor ) {
    testParserBySample( "TreeVisitor", "TreeVisitor", "TreeVisitor" );
}
