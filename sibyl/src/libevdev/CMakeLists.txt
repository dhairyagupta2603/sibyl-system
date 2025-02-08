cmake_minimum_required(VERSION 3.26)
project(libevdev 
    LANGUAGES C
)

include(ExternalProject)

message("${CMAKE_BINARY_DIR}")
message("${CMAKE_CURRENT_SOURCE_DIR}")

# Define the external project for libevdev
ExternalProject_Add(
    libevdev_ext
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_COMMAND ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> ./autogen.sh --prefix=${CMAKE_BINARY_DIR}/libevdev/ &&
                      ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> ./configure --prefix=${CMAKE_BINARY_DIR}/libevdev/
    # BUILD_COMMAND ${CMAKE_MAKE_PROGRAM}
    # INSTALL_COMMAND ${CMAKE_MAKE_PROGRAM} install
    BUILD_COMMAND ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> make
    INSTALL_COMMAND ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> make install
)

# Define output properties for the parent project
set(LIBEVDEV_INCLUDE_DIR ${CMAKE_BINARY_DIR}/libevdev/install/include PARENT_SCOPE)
set(LIBEVDEV_LIBRARY ${CMAKE_BINARY_DIR}/libevdev/install/lib/libevdev.so PARENT_SCOPE)
