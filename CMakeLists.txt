# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(BMPImageCreator VERSION 1.0)

# Specify the C standard (optional)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include the header files from the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the executable target
add_executable(BMPImageCreator src/main.c)

# Generate the compilation database (JSON file)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
