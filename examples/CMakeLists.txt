cmake_minimum_required(VERSION 3.15)

if(EMSCRIPTEN)
    # get markdown parser library
    include(FetchContent)
    FetchContent_Declare(
        maddy
        GIT_REPOSITORY https://github.com/progsource/maddy
        GIT_TAG master
    )
    FetchContent_MakeAvailable(maddy)
endif()

# all example targets
set(LPSM_EXAMPLES_TARGETS
    GenerateWord
    GenerateWords
    GenerateParagraph
    GenerateParagraphs
    GenerateSentence
    GenerateSentences
    GenerateDefaultLipsumSentence
    GenerateSentenceFragment
    Basic
    Markdown
    Advanced
    GenerateText
    Misc
    GenerateMarkdownHeader
    GenerateMarkdownEmphasis
    GenerateMarkdownLink
    GenerateMarkdownList
    GenerateMarkdownParagraph
    GenerateMarkdownParagraphs
    GenerateMarkdownText
    GenerateSlug
    GenerateURL
    Source
    Formats
)

# add executable + link to lipsum-cpp for each
foreach(target IN LISTS LPSM_EXAMPLES_TARGETS)
    add_executable(${target} "${CMAKE_CURRENT_SOURCE_DIR}/${target}.cpp")
    target_link_libraries(${target} lipsum-cpp)
endforeach()

if(EMSCRIPTEN)
    # link markdown example with markdown parser lib
    target_link_libraries(Markdown maddy)
endif()

# add c wrapper example if supported
if(LPSM_BUILD_CWRAPPER)
    add_executable(CWrapper "${CMAKE_CURRENT_SOURCE_DIR}/CWrapper.c")
    target_link_libraries(CWrapper lipsum-cpp)
endif()
