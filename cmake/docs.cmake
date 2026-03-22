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
