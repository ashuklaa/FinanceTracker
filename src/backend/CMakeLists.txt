add_library(ft_backend_lib backend_lib.cpp)

target_include_directories(ft_backend_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ft_backend_lib PRIVATE SQLiteCpp sqlite3)
