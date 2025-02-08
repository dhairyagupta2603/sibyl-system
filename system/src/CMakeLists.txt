include(Coverage)
include(Format)
include(CppCheck)
include(Doxygen)

# find dependencies
find_package(sibyl REQUIRED)

add_executable(sibyl-system main.cpp)

target_link_libraries(sibyl-system PUBLIC sibyl::sibyl)
target_include_directories(sibyl-system PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

InstrumentForCoverage(sibyl-system)
CleanCoverage(sibyl-system)
Format(sibyl-system .)
AddCppCheck(sibyl-system)
Doxygen(sibyl-system src)

# Installation
install(TARGETS sibyl-system RUNTIME COMPONENT runtime)



