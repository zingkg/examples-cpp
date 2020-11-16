cmake_minimum_required(VERSION 2.8)
include(CTest)

include_directories(${CMAKE_SOURCE_DIR}/Libraries/)
include_directories(${CMAKE_SOURCE_DIR})

file(GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Shapes/*.cpp")
file(GLOB TESTS_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Shapes/*.cpp")
add_executable(Test "Test.cpp" ${SRC} ${TESTS_SRC})
set_target_properties(Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output)
add_test(NAME Test COMMAND Test -s)
