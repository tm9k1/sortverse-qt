cmake_minimum_required(VERSION 3.15)

project(sortverse-qt)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if(WIN32)
    add_compile_definitions(WIN32=1)
elseif(UNIX)
    add_compile_definitions(UNIX=1)
endif()

add_subdirectory(src)

