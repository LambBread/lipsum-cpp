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

if(LPSM_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)

        # custom target running on sources
        add_custom_target(tidy
            COMMAND ${CLANG_TIDY_EXE} "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp" -- "-I${CMAKE_CURRENT_SOURCE_DIR}/src" -DLIPSUM_BUILD_STATIC
            COMMAND ${CLANG_TIDY_EXE} "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_static.cpp"
            COMMENT "Running clang-tidy on source files..."
            VERBATIM)
    else()
        message(WARNING "lipsum-cpp ---- cannot find clang-tidy. Target 'tidy' will not be available.")
    endif()
endif()

if(LPSM_AMALGAMATE)
    find_program(QUOM_EXE NAMES quom)
    if(QUOM_EXE)
        file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
        add_custom_target(amalgamate
            COMMAND ${QUOM_EXE} "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/bin/lipsum.hpp"
            COMMAND ${QUOM_EXE} "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum.h" "${CMAKE_CURRENT_SOURCE_DIR}/bin/lipsum.h"
            COMMAND ${QUOM_EXE} "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/bin/lipsum_h.cpp"
            COMMENT "Amalgamating with quom..."
            VERBATIM)
    else()
        message(WARNING "lipsum-cpp ---- cannot find quom. Target 'amalgamate' will not be available.")
    endif()
endif()

if(LPSM_BUILD_SAMPLE)
    # if chosen, find python
    find_package(Python COMPONENTS Interpreter REQUIRED)

    # add target
    add_custom_target(
        sample
        COMMAND ${Python_EXECUTABLE} split.py
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/scripts"
        VERBATIM
    )
endif()

if(LPSM_BUILD_VERSION)
    add_custom_target(version
        COMMAND ${CMAKE_COMMAND} 
        -DLPSM_VERSION=${PROJECT_VERSION} 
        -DLPSM_VERSION_MAJOR=${PROJECT_VERSION_MAJOR} 
        -DLPSM_VERSION_MINOR=${PROJECT_VERSION_MINOR} 
        -DLPSM_VERSION_PATCH=${PROJECT_VERSION_PATCH} 
        -DLPSM_VERSION_DEV=${LPSM_VERSION_DEV}
        -DPROJECT_DESCRIPTION="${PROJECT_DESCRIPTION}"
        -P ${CMAKE_CURRENT_SOURCE_DIR}/scripts/version.cmake
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        VERBATIM
    )
endif()

if(LPSM_BUILD_DOCS)
    # if building docs, find doxygen
    find_package(Doxygen REQUIRED)

    # if found, add custom target running on all builds
    # which builds docs
    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile")
        set(DOXYGEN_OUT "${CMAKE_CURRENT_SOURCE_DIR}/docs")
        add_custom_target(doc ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_IN}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
    endif()
endif()
