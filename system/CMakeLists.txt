cmake_minimum_required(VERSION 3.26)

project(
    Sibyl-System 
    DESCRIPTION "A crossplatform key logger to aggregate and analyze mouse and keyboard usage over time"
    VERSION 0.0.3
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuilds)
# include(CTest)

add_subdirectory(src)
# add_subdirectory(test)

include(Packaging)