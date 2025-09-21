
if(LPSM_BUILD_SAMPLE)
    find_package(Python COMPONENTS Interpreter REQUIRED)
    add_custom_target(
        sample ALL
        COMMAND ${Python_EXECUTABLE} split.py
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/scripts"
        COMMENT "Generating lipsum.inl"
    )
endif()
