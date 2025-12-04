cmake_minimum_required(VERSION 3.15)

set(LPSM_EXAMPLES_TARGETS
    GenerateWord
    GenerateWords
    GenerateParagraph
    GenerateParagraphs
    GenerateSentence
    GenerateSentences
    GenerateDefaultLipsumSentence
    GenerateSentenceFragment
    HTMLify
    FuncsX
    Basic
)
foreach(target IN LISTS LPSM_EXAMPLES_TARGETS)
    add_executable(${target} "${CMAKE_CURRENT_SOURCE_DIR}/${target}.cpp")
    target_link_libraries(${target} lipsum-cpp)
endforeach()

if(LPSM_BUILD_CWRAPPER)
    add_executable(CWrapper "${CMAKE_CURRENT_SOURCE_DIR}/CWrapper.c")
    target_link_libraries(CWrapper lipsum-cpp)
endif()
