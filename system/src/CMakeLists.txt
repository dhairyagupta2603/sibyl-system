include(Coverage)
include(Format)
include(CppCheck)
include(Doxygen)

# find dependencies
find_package(sibyl REQUIRED)

add_executable(sybil-system main.cpp)

target_link_libraries(sybil-system PUBLIC sibyl::sibyl)
target_include_directories(sybil-system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

InstrumentForCoverage(sybil-system)
CleanCoverage(sybil-system)
Format(sybil-system .)
AddCppCheck(sybil-system)
Doxygen(sybil-system src)

# Installation
install(TARGETS sybil-system RUNTIME COMPONENT runtime)



