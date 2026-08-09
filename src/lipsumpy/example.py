import ctypes
import lipsum_cpp

if __name__ == "__main__":
    # gen = lipsum_cpp.native_lib.lpsm_Generator(b"cat")
    # para_ptr = lipsum_cpp.native_lib.lpsm_Generator_paragraph(gen, 5, lipsum_cpp.NO_USELIPSUM)
    # para = ctypes.string_at(para_ptr)
    # print(para.decode("utf-8"))
    # lipsum_cpp.native_lib.lpsm_GeneratorDestroy(gen)
    # lipsum_cpp.native_lib.lpsm_DeleteString(para_ptr)

    print(lipsum_cpp.__version__)
    gen = lipsum_cpp.Generator("cat", 69)
    print(gen.paragraph(4, False))
