cmake_minimum_required(VERSION 3.15)
if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "Must compile JS binding under Emscripten!")
endif()
add_executable(lipsum
    "${CMAKE_CURRENT_SOURCE_DIR}/lipsum_binding_js.cpp"
)
target_link_libraries(lipsum embind lipsum-cpp)
set_target_properties(lipsum PROPERTIES
    SUFFIX ".js"
    LINK_FLAGS "-s MODULARIZE=1 -s EXPORT_NAME=createLipsumCpp"
)

