# static/shared
option(LPSM_BUILD_STATIC "Build as static library" OFF)
option(LPSM_BUILD_SHARED "Build as shared library" OFF)

# wrappers/bindings
option(LPSM_BUILD_CWRAPPER "Build C wrapper" OFF)
option(LPSM_BUILD_JSBIND "Build the JS WebAssembly binding" OFF)

# custom targets
option(LPSM_BUILD_EXAMPLES "Build examples" OFF)
option(LPSM_BUILD_DOCS "Build Doxygen docs" OFF)
option(LPSM_BUILD_CLI "Build lipsum-cpp CLI tool" OFF)
option(LPSM_FORMAT "Have support for running clang-format on sources" ON)
option(LPSM_BUILD_SAMPLE "Have support for running the Python script that generates sample.inl" ON)
option(LPSM_BUILD_VERSION "Have support for running the script that generates version header files" ON)

# executable suffix for WASM
option(LPSM_BUILD_ASHTML "Set the executable suffix to HTML for WASM builds" ON)
