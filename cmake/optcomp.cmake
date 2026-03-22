#empty sources
set(LPSM_SRCS "")

# messages for static/shared
if(LPSM_BUILD_STATIC)
    message(STATUS "lipsum-cpp ---- Building static")
endif()
if(LPSM_BUILD_SHARED)
    message(STATUS "lipsum-cpp ---- Building shared")
endif()

# shared/static add cpp to sources
if(LPSM_BUILD_STATIC OR LPSM_BUILD_SHARED)
    list(APPEND LPSM_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_static.cpp")
endif()

# c wrapper add wrapper to sources
if(LPSM_BUILD_CWRAPPER)
    message(STATUS "lipsum-cpp ---- Building C wrapper")
    list(APPEND LPSM_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp")
endif()

# commented out generator expression garbage
#set(lipsum_srcs
#    "$<IF:$<OR:$<BOOL:${LPSM_BUILD_STATIC}>,$<BOOL:${LPSM_BUILD_SHARED}>>,${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_static.cpp, \"\">"
#    "$<IF:$<BOOL:${LPSM_BUILD_CWRAPPER}>,${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp, \"\">"
#)
