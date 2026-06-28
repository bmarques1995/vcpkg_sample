set(TARGET_NAME server)

file(GLOB_RECURSE SERVER_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE SERVER_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.hpp")

find_package(spdlog REQUIRED)
find_package(Crow REQUIRED)

add_executable(${TARGET_NAME} ${SERVER_SRCS} ${SERVER_HDRS})
target_link_libraries(${TARGET_NAME} PUBLIC spdlog::spdlog Crow::Crow)

set_cxx_project_standards(${TARGET_NAME} 23 FALSE)

append_rpath(EXTRA_PATH "${CMAKE_PREFIX_PATH}/lib/${CMAKE_LIBRARY_ARCHITECTURE};${CMAKE_PREFIX_PATH}/lib;${CMAKE_PREFIX_PATH}/debug/lib")