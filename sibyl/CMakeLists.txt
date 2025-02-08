##########################################################################################
# Project Setup
cmake_minimum_required(VERSION 3.26)

project(
    Sibyl-System 
    DESCRIPTION "A linux library that logs all user actions to aggregate and analyze"
    VERSION 0.0.1
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuilds)
include(CTest)
include(Coverage)
include(Format)
include(CppCheck)
include(Doxygen)
include(BuildInfo)

add_subdirectory(src)
message("${CMAKE_BINARY_DIR}")


##########################################################################################
# Builidng and packaging 
BuildInfo(sibyl)
include(Packaging)