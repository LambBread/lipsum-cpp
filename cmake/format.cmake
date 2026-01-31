if(LPSM_FORMAT)
    find_program(CLANG_FORMAT_EXE NAMES clang-format)
    if(CLANG_FORMAT_EXE)
        file(GLOB LPSM_FORMAT_SOURCES
            "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum.h"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum.hpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum/*.hpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum/*.inl"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/jsbind/lipsum_binding_js.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/examples/CWrapper.c"
        )
        add_custom_target(format COMMAND ${CLANG_FORMAT_EXE} -i ${LPSM_FORMAT_SOURCES}
            COMMENT "Running clang-format on source files...")
    else()
        message(WARNING "lipsum-cpp ---- cannot find clang-format. Target 'format' will not be available.")
    endif()
endif()
