cmake_minimum_required(VERSION 3.6)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the project name
project(DiamondBank
    VERSION 1.0
    DESCRIPTION "A C++17 Project about creating a bank interface for the Diamond Bank"
    LANGUAGES CXX)

# Specify the source and include directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Add help tool for devs to test the program
option(DevHelp "Simplifies testing by creating the database wherever you called the program in" ON)
if(DevHelp)
    add_compile_options(-DDEVHELP)
endif()

# Recursively collect all source files (both .cpp and .h)
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.h")

# Retain folder hierarchy by specifying the source files with their full paths
source_group(TREE "${SRC_DIR}"
    PREFIX "Source Files"
    FILES ${SOURCES}])

# Set the output directories to avoid clutter in the root folder
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build/${CMAKE_GENERATOR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Ensure CMake files are also placed in the build folder
set(CMAKE_CACHEFILE_DIR "${CMAKE_BINARY_DIR}")

# Add the executable using the collected source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Optionally specify additional include directories if needed
# target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")

# Set the Visual Studio startup project
if (CMAKE_GENERATOR MATCHES "Visual Studio")
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()
