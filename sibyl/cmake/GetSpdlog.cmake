include(FetchContent)

FetchContent_Declare(SPDLOG
  GIT_REPOSITORY 
    https://github.com/gabime/spdlog.git
  GIT_TAG
    v1.15.1
)

option(SPDLOG_BUILD_EXAMPLES "Build spdlog examples" OFF)
option(SPDLOG_INSTALL "Generate the install target" OFF)
FetchContent_MakeAvailable(SPDLOG)