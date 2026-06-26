cmake_minimum_required(VERSION 3.28)

if(NOT CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    message(FATAL_ERROR "this project only works on Linux")
endif()

project(qchat VERSION 1.0 LANGUAGES CXX)

# 1. Include the built-in FetchContent module
include(FetchContent)

# 2. Declare the download location and version details
FetchContent_Declare(
    cmake_helpers
    GIT_REPOSITORY https://github.com/bmarques1995/cmake_helpers.git
    #GIT_TAG        v1.14.0 # Best practice: Use a specific tag or commit hash
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/cmake_helpers
)

# 3. Download the library and make its targets available
FetchContent_MakeAvailable(cmake_helpers)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/")

include(dep_tracer)
include(target_destination)

add_subdirectory(src)