cmake_minimum_required(VERSION 3.26)
project(libevdev LANGUAGES C)

include(ExternalProject)

set(LIBEVDEV_LOCAL_INSTALL_DIR "${CMAKE_BINARY_DIR}/libevdev")

# Define the external project for libevdev
ExternalProject_Add(
    libevdev_ext
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    CONFIGURE_COMMAND ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> ./autogen.sh --prefix=${LIBEVDEV_LOCAL_INSTALL_DIR} &&
                      ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> ./configure --prefix=${LIBEVDEV_LOCAL_INSTALL_DIR}
    # BUILD_COMMAND ${CMAKE_MAKE_PROGRAM}
    # INSTALL_COMMAND ${CMAKE_MAKE_PROGRAM} install
    BUILD_COMMAND ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> make
    INSTALL_COMMAND ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> make install
)

# Custom command to copy installed files to /usr/local
add_custom_command(
    OUTPUT copy_to_usr_local
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBEVDEV_LOCAL_INSTALL_DIR}/include/libevdev-1.0 /usr/local/include/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBEVDEV_LOCAL_INSTALL_DIR}/lib /usr/local/lib
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBEVDEV_LOCAL_INSTALL_DIR}/share /usr/local/share
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBEVDEV_LOCAL_INSTALL_DIR}/bin /usr/local/bin
    DEPENDS libevdev_ext
    COMMENT "Copying libevdev files to /usr/local"
)

# Define output properties for the parent project
set(LIBEVDEV_INCLUDE_DIR ${LIBEVDEV_LOCAL_INSTALL_DIR}/include/libevdev-1.0 PARENT_SCOPE)
set(LIBEVDEV_LIBRARY ${LIBEVDEV_LOCAL_INSTALL_DIR}/lib/libevdev.so PARENT_SCOPE)




# Ensure the copy step is executed as part of the build process
add_custom_target(copy_libevdev_to_usr_local ALL
    DEPENDS copy_to_usr_local
)
