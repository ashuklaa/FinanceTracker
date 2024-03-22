cmake_minimum_required(VERSION 3.22)
project(
  "FinanceTracker"
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(libs)
add_subdirectory(tests)

# If you want the compile_commands.json to be copied to your project root
# (useful with certain tools)
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(COMPILATION_DATABASE_FILE
      "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
  if(EXISTS "${COMPILATION_DATABASE_FILE}")
    file(COPY ${COMPILATION_DATABASE_FILE}
         DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
  endif()
endif()

# Add your source files here add_executable(FinanceTracker .cpp) # Change
# executable name and source files accordingly

# If you have include directories, link libraries, etc., specify those here
# include_directories(your/include/directories)
# target_link_libraries(YourExecutableName your_libraries_to_link)k
