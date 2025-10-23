#set(lipsum_srcs "")
if(LPSM_BUILD_STATIC)
    message("Building static")
    #list(APPEND lipsum_srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum.cpp")
endif()
if(LPSM_BUILD_CWRAPPER)
    message("Building C wrapper")
    #list(APPEND lipsum_srcs "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp")
endif()
set(lipsum_srcs
    "$<IF:$<BOOL:${LPSM_BUILD_STATIC}>,${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum.cpp, \"\">"
    "$<IF:$<BOOL:${LPSM_BUILD_CWRAPPER}>,${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp, \"\">"
)
