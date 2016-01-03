set(SOURCE_FILES src/main.cpp)
add_definitions(-DCORO_FIBER=1)
add_executable(sim ${SOURCE_FILES})
target_link_libraries(sim coro cppformat)