cmake_minimum_required(VERSION 2.8)
include(CTest)

include_directories(${CMAKE_SOURCE_DIR}/Libraries/)
include_directories(${CMAKE_SOURCE_DIR})

file(GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Common/*.cpp")
file(GLOB HTTP_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/Common/HTTP/*.cpp")
file(GLOB TESTS_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Common/*.cpp")
file(GLOB CONTAINER_TESTS_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Common/Containers/*.cpp")
file(GLOB HTTP_TESTS_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Common/HTTP/*.cpp")
add_executable(Test "Test.cpp" ${SRC} ${HTTP_SRC} ${TESTS_SRC} ${CONTAINER_TESTS_SRC} ${HTTP_TESTS_SRC})
set_target_properties(Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output)
add_test(NAME Test COMMAND Test -s)
