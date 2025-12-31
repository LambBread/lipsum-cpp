if(LPSM_BUILD_STATIC)
    message("Building static")
endif()
if(LPSM_BUILD_SHARED)
    message("Building shared")
endif()
if(LPSM_BUILD_CWRAPPER)
    message("Building C wrapper")
endif()
set(lipsum_srcs
    "$<IF:$<OR:$<BOOL:${LPSM_BUILD_STATIC}>,$<BOOL:${LPSM_BUILD_SHARED}>>,${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_static.cpp, \"\">"
    "$<IF:$<BOOL:${LPSM_BUILD_CWRAPPER}>,${CMAKE_CURRENT_SOURCE_DIR}/src/lipsum_h.cpp, \"\">"
)
