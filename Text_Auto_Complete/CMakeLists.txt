cmake_minimum_required(VERSION 2.8)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(TextAutoComplete)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -g -std=c++11")
message("Making with CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/Output/Install)

file(GLOB TEXT_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Text/*.cpp")
add_executable(TextAutoComplete ${TEXT_SRC})
set_target_properties(TextAutoComplete PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Output)
