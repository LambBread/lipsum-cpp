# from ._ctypes_loader import native_lib
import ctypes
from ._low_level import native_lib

__version__ = str(native_lib.lpsm_internal_Version__(), "utf-8")
USELIPSUM = True
NO_USELIPSUM = False
HTML = True
MARKDOWN = False
OBJECT = True
ARRAY = False
BOLD = True
ITALIC = False
ORDERED = True
UNORDERED = False
IPV4 = False
IPV6 = True
NOPORT = False
PORT = True
CSC_CAMEL_CASE = 0
CSC_PASCAL_CASE = 1
CSC_SNAKE_CASE = 2
CSC_SHOUTY_CASE = 3
CSC_KEBAB_CASE = 4
CSC_TRAIN_CASE = 5
CODEL_CPP = 0
CODEL_PYTHON = 1
CODEL_RUST = 2
CODEL_C = 3
CODEL_JAVASCRIPT = 4

# TODO: better documentation, more functions

class LipsumString:
    def __init__(self, ptr:int):
        self.__ptr = ptr

    def __str__(self):
        str_at = ctypes.string_at(self.__ptr)
        return str_at.decode("utf-8")

    def __del__(self):
        native_lib.lpsm_DeleteString(self.__ptr)

class Generator:
    def __init__(self, source_name:str = "lorem", seed = None):
        if seed is None:
            self.__gen = native_lib.lpsm_Generator(bytes(source_name, "utf-8"))
        else:
            self.__gen = native_lib.lpsm_GeneratorSeeded(bytes(source_name, "utf-8"), seed)

    def __del__(self):
        native_lib.lpsm_GeneratorDestroy(self.__gen)

    def paragraph(self, num:int = 1, use_lipsum:bool = True):
        return LipsumString(native_lib.lpsm_Generator_paragraph(self.__gen, num, use_lipsum))

# if __name__ == "__main__":
#     print(native_lib.lpsm_internal_Version__())
#     handle = native_lib.lpsm_Generator(b"lorem")
#     print(native_lib.lpsm_Generator_word(handle, 20))
#     native_lib.lpsm_GeneratorDestroy(handle)
