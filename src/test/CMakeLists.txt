cmake_minimum_required(VERSION 3.20)
add_executable(lpsmcpp-test
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)
target_link_libraries(lpsmcpp-test lipsum-cpp)
