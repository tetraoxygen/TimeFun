cmake_minimum_required(VERSION 3.16)

project(TimeFun)

add_executable(TimeFun TimeFun.cpp)

install(TARGETS TimeFun)

enable_testing()
add_test(NAME TimeFun COMMAND TimeFun)


IF (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(TimeFun -static)
ENDIF()