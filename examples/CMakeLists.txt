cmake_minimum_required(VERSION 3.20)

# all example targets
set(LPSM_EXAMPLES_TARGETS
    Generator
    GeneratorFormats
    Markdown
    Advanced
    Misc
    Source
)

# add executable + link to lipsum-cpp for each
foreach(target IN LISTS LPSM_EXAMPLES_TARGETS)
    add_executable(${target} "${CMAKE_CURRENT_SOURCE_DIR}/${target}.cpp")
    target_link_libraries(${target} lipsum-cpp)
endforeach()

# add c wrapper example if supported
if(LPSM_BUILD_CWRAPPER)
    add_executable(CWrapper "${CMAKE_CURRENT_SOURCE_DIR}/CWrapper.c")
    target_link_libraries(CWrapper lipsum-cpp)
endif()
