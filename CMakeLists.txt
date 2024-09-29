cmake_minimum_required(VERSION 3.10)

# Set the project name
project(DiamondBank)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source and include directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# Recursively collect all source files (both .cpp and .h)
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.h")

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/CMake")

# Add the executable using the collected source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Optionally specify additional include directories if needed
# target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
