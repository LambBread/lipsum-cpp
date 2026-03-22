# if building as html and emscripten, give message and set exe suffix
if(EMSCRIPTEN AND LPSM_BUILD_ASHTML)
    message(STATUS "lipsum-cpp ---- Doing WebAssembly HTML build")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

# if building examples, message and add subdir
if(LPSM_BUILD_EXAMPLES)
    message(STATUS "lipsum-cpp ---- Building examples")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/examples")
endif()

# if building emscripten and JS binding, add as subdir
if(EMSCRIPTEN AND LPSM_BUILD_JSBIND)
    message(STATUS "lipsum-cpp ---- Building JS binding")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/jsbind/")
endif()
