import ctypes
from ._ctypes_loader import native_lib
from .exceptions import exceptions

native_lib.lpsm_internal_Version__.argtypes = []
native_lib.lpsm_internal_Version__.restype = ctypes.c_char_p
native_lib.lpsm_internal_DeleteString.argtypes = [ctypes.c_char_p]
