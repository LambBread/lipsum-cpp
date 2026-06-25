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

if(LPSM_MIN_BUILD)
    message(STATUS "lipsum-cpp ---- Doing minimum build")
endif()

# if building tests, enable test and add subdirectory
if(LPSM_BUILD_TEST AND NOT EMSCRIPTEN)
    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/test")
    set(LPSM_TESTS_LIST
        count_words
        count_fragments
        count_sentences
        word_count_in_bounds
        word_count_equal
        fragment_count_in_bounds
        sentence_count_in_bounds
        sentence_count_equal
        paragraph_count_in_bounds
        paragraph_count_equal
    )
    if(NOT LPSM_MIN_BUILD)
        list(APPEND LPSM_TESTS_LIST
            md_sentence_count_in_bounds
            md_paragraph_count_equal
            md_text_count_equal
        )
    endif()
    foreach(test IN LISTS LPSM_TESTS_LIST)
        add_test(NAME ${test} COMMAND lpsmcpp-test ${test})
    endforeach()
endif()

# if building cli, message and add subdir
if(LPSM_BUILD_CLI AND NOT EMSCRIPTEN)
    message(STATUS "lipsum-cpp ---- Building CLI")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/cli/")
endif()

# if building emscripten and JS binding, add as subdir
if(EMSCRIPTEN AND LPSM_BUILD_JSBIND)
    message(STATUS "lipsum-cpp ---- Building JS binding")
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/jsbind/")
endif()
