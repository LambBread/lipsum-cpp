cmake_minimum_required(VERSION 3.20)
add_executable(lpsmcpp-test
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)
target_link_libraries(lpsmcpp-test lipsum-cpp)


add_custom_target(clean_benchmark_log
    COMMAND ${CMAKE_COMMAND} -E rm -f benchmark_log.txt
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Deleting old log"
    USES_TERMINAL
    VERBATIM
)

set(LPSM_BENCHMARKS
    benchmark_words
    benchmark_sentences
    benchmark_paragraphs
)
if(NOT LPSM_MIN_BUILD)
    list(APPEND LPSM_BENCHMARKS
        benchmark_md_paragraphs benchmark_md_text
    )
endif()
foreach(bench IN LISTS LPSM_BENCHMARKS)
    add_custom_target(
        ${bench} COMMAND lpsmcpp-test ${bench} >> benchmark_log.txt
        DEPENDS lpsmcpp-test
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Running benchmark ${bench}"
        USES_TERMINAL
        VERBATIM
    )
endforeach()

add_custom_target(benchmark
    DEPENDS clean_benchmark_log lpsmcpp-test ${LPSM_BENCHMARKS}
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Running benchmarks"
    VERBATIM
)

