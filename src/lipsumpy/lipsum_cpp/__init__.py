# from ._ctypes_loader import native_lib
from ._low_level import native_lib

LPSM_USELIPSUM = True
LPSM_NO_USELIPSUM = False
LPSM_HTML = True
LPSM_MARKDOWN = False
LPSM_OBJECT = True
LPSM_ARRAY = False
LPSM_BOLD = True
LPSM_ITALIC = False
LPSM_ORDERED = True
LPSM_UNORDERED = False
LPSM_IPV4 = False
LPSM_IPV6 = True
LPSM_NOPORT = False
LPSM_PORT = True
LPSM_CSC_CAMEL_CASE = 0
LPSM_CSC_PASCAL_CASE = 1
LPSM_CSC_SNAKE_CASE = 2
LPSM_CSC_SHOUTY_CASE = 3
LPSM_CSC_KEBAB_CASE = 4
LPSM_CSC_TRAIN_CASE = 5
LPSM_CODEL_CPP = 0
LPSM_CODEL_PYTHON = 1
LPSM_CODEL_RUST = 2
LPSM_CODEL_C = 3
LPSM_CODEL_JAVASCRIPT = 4

# if __name__ == "__main__":
#     print(native_lib.lpsm_internal_Version__())
#     handle = native_lib.lpsm_Generator(b"lorem")
#     print(native_lib.lpsm_Generator_word(handle, 20))
#     native_lib.lpsm_GeneratorDestroy(handle)
