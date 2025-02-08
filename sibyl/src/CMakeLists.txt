add_subdirectory(spdlog)
add_subdirectory(libevdev)

add_library(sibyl SHARED 
    sibyl.cpp
)

message("${LIBEVDEV_INCLUDE_DIR}")

# Specify include directories
target_include_directories(sibyl PUBLIC 
    # During build
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>  
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include>  
    $<BUILD_INTERFACE:${LIBEVDEV_INCLUDE_DIR}>  

    # After installation
    $<INSTALL_INTERFACE:include>                            
)

# Link spdlog to the library
target_link_libraries(sibyl PRIVATE spdlog::spdlog evdev)

# Set the version for the library
set_target_properties(sibyl PROPERTIES
    VERSION 1.0.1
    SOVERSION 1
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/sibyl.hpp"
)

# Install the library
install(TARGETS sibyl
    EXPORT sibylTargets
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/sibyl
)

# Create and install an export file
install(EXPORT sibylTargets
    FILE sibylConfig.cmake
    NAMESPACE sibyl::
    DESTINATION lib/cmake/sibyl
)