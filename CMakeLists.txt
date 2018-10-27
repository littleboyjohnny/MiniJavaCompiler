cmake_minimum_required(VERSION 3.3)
project(MiniJavaCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_custom_target(
        parser
        COMMAND make parser
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        lexer
        COMMAND make lexer
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# fake executable
# add all source files just for clion inspection support
add_executable(fake parser.cpp lexer.cpp AST/interfaces/Goal/Goal.hpp)
