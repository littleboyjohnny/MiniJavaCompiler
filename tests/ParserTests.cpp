#define PARSER_DEBUG 1

#include "gtest/gtest.h"
#include "../parser/parser.h"
#include "../parser/parser.cpp"
#include "ParserTestYYLEX.cpp"

#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>

std::string pathToInputs = "../tests/LexerTestsFiles/correct/";
std::string pathToKeys = "../tests/ParserTestsFiles/correct/";
std::string pathToResults = "../tests/ParserTestsFiles/results/";

TEST( ParserTests, sample1 )
{
    std::string pathToResult = pathToResults + "sample1";
    std::string pathToSample = pathToInputs + "sample1";
    std::string pathToKey = pathToKeys + "sample1";

    //int temp_stdout = dup(1);
    FILE* toResults = freopen( pathToResult.c_str(), "w", stdout );
    if (toResults == NULL)
        printf("File can not be reopened\n");

    Builder builder( pathToSample.c_str() );
    IAcceptable * goal = nullptr;
    yyparse( goal );

    fclose(stdout);
    //stdout = fdopen(temp_stdout, "w");

    std::ifstream fresult( pathToResult.c_str(), std::ifstream::in );
    if ( !fresult.is_open() )
        printf( "File with results can not be opened\n" );
    std::string resultLine;
    std::ifstream fkeys( pathToKey.c_str(), std::ifstream::in );
    if ( !fkeys.is_open() )
        printf( "File with keys can not be opened\n" );
    std::string keyLine;
    while(std::getline(fresult, resultLine) && std::getline(fkeys, keyLine)) {
        ASSERT_EQ( resultLine, keyLine );
    }
    if (std::getline(fresult, resultLine)) {
        FAIL() << "Too many rules\n";
    }
    if (std::getline(fkeys, keyLine)) {
        FAIL() << "Not enough rules\n";
    }
    fresult.close();
    fkeys.close();
}

/*
TEST(St, TestingTest1)
{
    printf("Test2");
    Builder builder(2);
    IAcceptable * goal = nullptr;
    yyparse(goal);
    ASSERT_EQ(1, 1);
}
*/