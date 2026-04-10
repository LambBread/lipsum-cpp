# lipsum-cpp JS binding

This is a binding to JavaScript using embind + Emscripten. To use, call functions and create objects with the 
`lpsm_` prefix before `Module`. Just like the C wrapper, manually provide arguments to functions. 
See [`JSBinding.html`](../../examples/JSBinding.html) or read [`lipsum_binding_js.cpp`](./lipsum_binding_js.cpp) for more info.
