cmake_minimum_required(VERSION 3.13)

project(synacor)

file(GLOB_RECURSE synacor_SRC "src/*.cpp" "src/*.hpp")

add_executable(synacor ${synacor_SRC})

set(EXECUTABLE_NAME "synacor")
set(EXECUTABLE_OUTPUT_PATH "../bin")

set(CMAKE_CXX_STANDARD 17)

install(TARGETS synacor DESTINATION bin)
