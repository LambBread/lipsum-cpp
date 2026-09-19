"""@file _low_level.py

@brief Set up lipsum-cpp's shared library function arguments.

Set up lipsum-cpp's shared library function arguments using native ctypes.
This file is under the BSD Zero-Clause License.

@copyright Copyright (c) 2026 LambBread

@author LambBread from github.com
"""

import ctypes
from ._ctypes_loader import native_lib
from .custom_exceptions import LipsumCppException

native_lib.lpsm_internal_Version__.argtypes = []
native_lib.lpsm_DeleteString.argtypes = [ctypes.c_void_p]
native_lib.lpsm_GenerateDefaultLipsumSentence.argtypes = []
native_lib.lpsm_CountWords.argtypes = [ctypes.c_char_p]
native_lib.lpsm_CountSentenceFragments.argtypes = [ctypes.c_char_p]
native_lib.lpsm_CountSentences.argtypes = [ctypes.c_char_p]
native_lib.lpsm_CountParagraphs.argtypes = [ctypes.c_char_p, ctypes.c_int]
native_lib.lpsm_ConvertFormat.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_int]
native_lib.lpsm_Generator.argtypes = [ctypes.c_char_p]
native_lib.lpsm_GeneratorSeeded.argtypes = [ctypes.c_char_p, ctypes.c_int]
native_lib.lpsm_GeneratorDestroy.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_load_source.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
native_lib.lpsm_Generator_load_seed.argtypes = [ctypes.c_void_p, ctypes.c_int]
native_lib.lpsm_Generator_change_setting.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_int, ctypes.c_int]
native_lib.lpsm_Generator_toggle_lazy.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_word.argtypes = [ctypes.c_void_p, ctypes.c_int]
native_lib.lpsm_Generator_fragment.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_sentence.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_bool]
native_lib.lpsm_Generator_paragraph.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_bool]
native_lib.lpsm_Generator_text.argtypes = [ctypes.c_void_p, ctypes.c_bool]
native_lib.lpsm_Generator_scramble.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_char, ctypes.c_char]
native_lib.lpsm_Generator_url.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_plain_url.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_email.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_slug.argtypes = [ctypes.c_void_p, ctypes.c_char]
native_lib.lpsm_Generator_case_slug.argtypes = [ctypes.c_void_p, ctypes.c_int]
native_lib.lpsm_Generator_code.argtypes = [ctypes.c_void_p, ctypes.c_int]
native_lib.lpsm_Generator_ip_addr.argtypes = [ctypes.c_void_p, ctypes.c_bool, ctypes.c_bool]
native_lib.lpsm_Generator_phone_number.argtypes = [ctypes.c_void_p]
native_lib.lpsm_Generator_fmt_paragraph.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_bool, ctypes.c_bool]
native_lib.lpsm_Generator_fmt_text.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_bool]
native_lib.lpsm_Generator_fmt_header.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_bool]
native_lib.lpsm_Generator_fmt_emphasis.argtypes = [ctypes.c_void_p, ctypes.c_bool, ctypes.c_bool]
native_lib.lpsm_Generator_fmt_link.argtypes = [ctypes.c_void_p, ctypes.c_bool]
native_lib.lpsm_Generator_fmt_list.argtypes = [ctypes.c_void_p, ctypes.c_bool, ctypes.c_bool]
native_lib.lpsm_Generator_xml.argtypes = [ctypes.c_void_p, ctypes.c_int]
native_lib.lpsm_Generator_json.argtypes = [ctypes.c_void_p, ctypes.c_int, ctypes.c_bool]
native_lib.lpsm_Generator_json_value.argtypes = [ctypes.c_void_p, ctypes.c_int]
native_lib.lpsm_Generator_csv.argtypes = [ctypes.c_void_p]

native_lib.lpsm_internal_Version__.restype = ctypes.c_char_p
native_lib.lpsm_GenerateDefaultLipsumSentence.restype = ctypes.c_void_p
native_lib.lpsm_CountWords.restype = ctypes.c_int
native_lib.lpsm_CountSentenceFragments.restype = ctypes.c_int
native_lib.lpsm_CountSentences.restype = ctypes.c_int
native_lib.lpsm_CountParagraphs.restype = ctypes.c_int
native_lib.lpsm_ConvertFormat.restype = ctypes.c_void_p
native_lib.lpsm_Generator.restype = ctypes.c_void_p
native_lib.lpsm_GeneratorSeeded.restype = ctypes.c_void_p
native_lib.lpsm_Generator_word.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fragment.restype = ctypes.c_void_p
native_lib.lpsm_Generator_sentence.restype = ctypes.c_void_p
native_lib.lpsm_Generator_paragraph.restype = ctypes.c_void_p
native_lib.lpsm_Generator_text.restype = ctypes.c_void_p
native_lib.lpsm_Generator_scramble.restype = ctypes.c_void_p
native_lib.lpsm_Generator_url.restype = ctypes.c_void_p
native_lib.lpsm_Generator_plain_url.restype = ctypes.c_void_p
native_lib.lpsm_Generator_email.restype = ctypes.c_void_p
native_lib.lpsm_Generator_slug.restype = ctypes.c_void_p
native_lib.lpsm_Generator_case_slug.restype = ctypes.c_void_p
native_lib.lpsm_Generator_code.restype = ctypes.c_void_p
native_lib.lpsm_Generator_ip_addr.restype = ctypes.c_void_p
native_lib.lpsm_Generator_phone_number.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fmt_paragraph.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fmt_text.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fmt_header.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fmt_emphasis.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fmt_link.restype = ctypes.c_void_p
native_lib.lpsm_Generator_fmt_list.restype = ctypes.c_void_p
native_lib.lpsm_Generator_xml.restype = ctypes.c_void_p
native_lib.lpsm_Generator_json.restype = ctypes.c_void_p
native_lib.lpsm_Generator_json_value.restype = ctypes.c_void_p
native_lib.lpsm_Generator_csv.restype = ctypes.c_void_p
