if(LPSM_FORMAT)
    # if formatting and clang format found
    find_program(CLANG_FORMAT_EXE NAMES clang-format)
    if(CLANG_FORMAT_EXE)
        # sources globbing
        file(GLOB_RECURSE LPSM_FORMAT_SOURCES
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.inl"
            "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.c"
        )

        # custom target running on sources
        add_custom_target(format COMMAND ${CLANG_FORMAT_EXE} -i ${LPSM_FORMAT_SOURCES}
            COMMENT "Running clang-format on source files..."
            VERBATIM)
    else()
        message(WARNING "lipsum-cpp ---- cannot find clang-format. Target 'format' will not be available.")
    endif()
endif()
