cmake_minimum_required(VERSION 3.20)
add_executable(lpsmcpp-cli
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
)
add_executable(lpsmcpp-interactive "${CMAKE_CURRENT_SOURCE_DIR}/interactive.cpp")
target_link_libraries(lpsmcpp-cli lipsum-cpp)
target_link_libraries(lpsmcpp-interactive lipsum-cpp)

include(GNUInstallDirs)
install(TARGETS lpsmcpp-cli DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(TARGETS lpsmcpp-interactive DESTINATION "${CMAKE_INSTALL_BINDIR}")
