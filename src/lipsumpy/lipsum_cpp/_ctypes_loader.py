"""@file _ctypes_loader.py

@brief Handles loading lipsum-cpp's dynamic library.

This file handles loading lipsum-cpp's dynamic library. 
This file is under the BSD Zero-Clause License.

@copyright Copyright (c) 2026 LambBread

@author LambBread from github.com
"""

import ctypes
import os
import sys
from .custom_exceptions import LipsumCppException

def load_lipsum_cpp() -> ctypes.CDLL:
    """@brief Load lipsum-cpp's dynamic library.

       @since 0.5.4
    
       @return ctypes.CDLL The dynamic library.
    """
    if sys.platform == "win32":
        lib_name = "lipsum-cpp.dll"
    elif sys.platform == "darwin":
        lib_name = "liblipsum-cpp.dylib"
    else:
        lib_name = "liblipsum-cpp.so"
    current_dir = os.path.abspath(os.path.dirname(__file__))
    lib_path = os.path.join(current_dir, lib_name)

    if not os.path.exists(lib_path):
        lib_path = os.path.join(current_dir, "..", "..", lib_name)

    if not os.path.exists(lib_path):
        raise LipsumCppException(f"Could not find native package: {lib_name} at expected {lib_path}.")

    try:
        if sys.platform == "win32":
            return ctypes.CDLL(lib_path)
        else:
            return ctypes.CDLL(lib_path, mode=os.RTLD_GLOBAL)
    except Exception as e:
        raise LipsumCppException(f"Failed to load native library from {lib_path}: {e}")

native_lib = load_lipsum_cpp()
