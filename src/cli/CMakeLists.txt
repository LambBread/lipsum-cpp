cmake_minimum_required(VERSION 3.15)
add_executable(lpsmcpp-cli
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)
target_link_libraries(lpsmcpp-cli lipsum-cpp)

include(GNUInstallDirs)
install(TARGETS lpsmcpp-cli DESTINATION "${CMAKE_INSTALL_BINDIR}")
