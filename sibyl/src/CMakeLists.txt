add_library(sibyl SHARED 
    sibyl.cpp
)

# Specify include directories
target_include_directories(sibyl PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  # During build
    $<INSTALL_INTERFACE:include>                            # After installation
)

# Set the version for the library
set_target_properties(sibyl PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/sibyl.hpp"
)

# Install the library
install(TARGETS sibyl
    EXPORT sibylTargets
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

# Create and install an export file
install(EXPORT sibylTargets
    FILE sibylConfig.cmake
    NAMESPACE sibyl::
    DESTINATION lib/cmake/sibyl
)