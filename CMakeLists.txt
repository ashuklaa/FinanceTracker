# CMake Minimum Version
cmake_minimum_required(VERSION 3.16)

# Project Description
project(
  FinanceTracker
  VERSION 1.0
  LANGUAGES CXX)

# C++20 Standard Set
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# create compile_commands.json for clangd linting
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find Qt
find_package(
  Qt6
  COMPONENTS Widgets
  REQUIRED)

# Include frontend and backend in final compile
add_subdirectory(src/frontend)
add_subdirectory(src/backend)
add_subdirectory(tests)
add_subdirectory(extern/SQLiteCpp)
add_subdirectory(extern/cryptopp)
