# Specify the minimum Cmake Version
cmake_minimum_required(VERSION 3.20.0)

#Name the project
project(
    hello_world
    VERSION 1.0
    DESCRIPTION "THE BARE MINIMUM"
    LANGUAGES C
)

#create a static library target named "my_lib"
add_library(
    my_lib
    STATIC
    src/my_lib.c
)

#Set the include directories
target_include_directories(
    my_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#creating executable target
add_executable(
    ${PROJECT_NAME}
    src/main.c
)

#LINK the library
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    my_lib
)