cmake_minimum_required(VERSION 3.15)
project(lipsum-cpp VERSION 0.4.3 LANGUAGES C CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# include configuration files
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/options.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/sample.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/docs.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/examples.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/optcomp.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/format.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/version.cmake")

if(LPSM_BUILD_STATIC AND LPSM_BUILD_SHARED)
    message(FATAL_ERROR "lipsum-cpp ---- cannot build both static and shared!")
endif()

if(LPSM_BUILD_STATIC)
    # static library

    add_library(lipsum-cpp STATIC "${LPSM_SRCS}")
    
    # definitions
    target_compile_definitions(lipsum-cpp PUBLIC LIPSUM_BUILD_STATIC)
elseif(LPSM_BUILD_SHARED)
    # shared library

    add_library(lipsum-cpp SHARED "${LPSM_SRCS}")
    
    # definitions
    target_compile_definitions(lipsum-cpp 
        PUBLIC LIPSUM_BUILD_STATIC LIPSUM_BUILD_SHARED 
        PRIVATE LIPSUM_EXPORT_SHARED
    )
else()
    # header only

    add_library(lipsum-cpp INTERFACE)
endif()

#add_library(lipsum-cpp::lipsum-cpp ALIAS lipsum-cpp)

if(LPSM_BUILD_SHARED OR LPSM_BUILD_STATIC)
    # c++20
    target_compile_features(lipsum-cpp PUBLIC cxx_std_20)
    
    # include directories
    target_include_directories(lipsum-cpp PUBLIC 
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/lipsum-cpp>"
    )
else()

    # c++20
    target_compile_features(lipsum-cpp INTERFACE cxx_std_20)
    
    # include directories
    target_include_directories(lipsum-cpp INTERFACE 
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/lipsum-cpp>")
endif()

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/install.cmake")
