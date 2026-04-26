cmake_minimum_required(VERSION 3.15)

# all example targets
set(LPSM_EXAMPLES_TARGETS
    GenerateWord
    GenerateWords
    GenerateParagraph
    GenerateParagraphs
    GenerateSentence
    GenerateSentences
    GenerateSentenceFragment
    Generator
    GeneratorFormats
    Markdown
    Advanced
    GenerateText
    Misc
    Source
    Formats
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
