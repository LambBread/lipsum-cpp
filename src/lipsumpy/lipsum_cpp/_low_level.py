import ctypes
from _ctypes_loader import native_lib
from custom_exceptions import LipsumCppException

native_lib.lpsm_internal_Version__.argtypes = []
native_lib.lpsm_internal_Version__.restype = ctypes.c_char_p
native_lib.lpsm_DeleteString.argtypes = [ctypes.c_char_p]
native_lib.lpsm_Generator.argtypes = [ctypes.c_char_p]
native_lib.lpsm_Generator.restype = ctypes.c_void_p
native_lib.lpsm_GeneratorSeeded.argtypes = [ctypes.c_char_p, ctypes.c_int]
native_lib.lpsm_GeneratorSeeded.restype = ctypes.c_void_p
native_lib.lpsm_GeneratorDestroy.argtypes = [ctypes.c_void_p]


