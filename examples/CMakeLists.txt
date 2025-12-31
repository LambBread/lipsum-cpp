cmake_minimum_required(VERSION 3.15)
include(FetchContent)
FetchContent_Declare(
    maddy
    GIT_REPOSITORY https://github.com/progsource/maddy
    GIT_TAG master
)
FetchContent_MakeAvailable(maddy)
set(LPSM_EXAMPLES_TARGETS
    GenerateWord
    GenerateWords
    GenerateParagraph
    GenerateParagraphs
    GenerateSentence
    GenerateSentences
    GenerateDefaultLipsumSentence
    GenerateSentenceFragment
    FuncsX
    Basic
    Markdown
    Advanced
)
foreach(target IN LISTS LPSM_EXAMPLES_TARGETS)
    add_executable(${target} "${CMAKE_CURRENT_SOURCE_DIR}/${target}.cpp")
    target_link_libraries(${target} lipsum-cpp)
endforeach()
target_link_libraries(Markdown maddy)

if(LPSM_BUILD_CWRAPPER)
    add_executable(CWrapper "${CMAKE_CURRENT_SOURCE_DIR}/CWrapper.c")
    target_link_libraries(CWrapper lipsum-cpp)
endif()
