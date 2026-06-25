# static/shared
option(LPSM_BUILD_STATIC "Build as static library" ON)
option(LPSM_BUILD_SHARED "Build as shared library" OFF)

# wrappers/bindings
option(LPSM_BUILD_CWRAPPER "Build C wrapper" ON)
option(LPSM_BUILD_JSBIND "Build the JS WebAssembly binding" ON)

option(LPSM_MIN_BUILD "Build a minimum build" OFF)
option(LPSM_QUIET "Disable runtime warnings" OFF)

# custom targets
option(LPSM_BUILD_EXAMPLES "Build examples" OFF)
option(LPSM_BUILD_EXTRA_EXAMPLES "Build advanced examples" OFF)
option(LPSM_BUILD_TEST "Build unit tests" ON)
option(LPSM_BUILD_DOCS "Build Doxygen docs" OFF)
option(LPSM_BUILD_CLI "Build lipsum-cpp CLI tool" OFF)
option(LPSM_FORMAT "Have support for running clang-format on sources" ON)
option(LPSM_BUILD_SAMPLE "Have support for running the Python script that generates sample.inl" ON)
option(LPSM_BUILD_VERSION "Have support for running the script that generates version header files" ON)
option(LPSM_TIDY "Have support for running clang-tidy on sources" ON)
option(LPSM_AMALGAMATE "Have support for amalgamating single-header builds" OFF)

# executable suffix for WASM
option(LPSM_BUILD_ASHTML "Set the executable suffix to HTML for WASM builds" ON)

option(LPSM_VERSION_DEV "Is lipsum-cpp in a work-in-progress version?" ON)
