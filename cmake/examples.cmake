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

# if building tests, enable test and add subdirectory
if(LPSM_BUILD_TEST)
    enable_testing()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/test")
    add_test(NAME count_words COMMAND lpsmcpp-test count_words)
    add_test(NAME count_sentences COMMAND lpsmcpp-test count_sentences)
    add_test(NAME word_count_in_bounds COMMAND lpsmcpp-test word_count_in_bounds)
    add_test(NAME word_count_equal COMMAND lpsmcpp-test word_count_equal)
    add_test(NAME sentence_count_in_bounds COMMAND lpsmcpp-test sentence_count_in_bounds)
    add_test(NAME sentence_count_equal COMMAND lpsmcpp-test sentence_count_equal)
    add_test(NAME md_sentence_count_in_bounds COMMAND lpsmcpp-test md_sentence_count_in_bounds)
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
