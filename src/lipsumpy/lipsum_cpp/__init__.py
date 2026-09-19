"""@package lipsum_cpp

@brief Main file of lipsum-cpp Python wrapper

This is the main file of lipsum-cpp's Python wrapper.
This file is under the BSD Zero-Clause License.

@example PyWrapper.py

@copyright Copyright (c) 2026 LambBread

@author LambBread from github.com
"""

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

class CaseSlugCase:
    """@brief Cases used by lipsum_cpp.Generator.case_slug()
     
     @since 0.5.4
     
     Types of cases used by lipsum_cpp.Generator.case_slug(). Includes various
     types such as camel case, snake case, etc.
    """
    CamelCase, PascalCase, SnakeCase, ShoutyCase, KebabCase, TrainCase = range(6)

class CodeLanguage:
    """@brief Languages used by lipsum_cpp.Generator.code()
    
     @since 0.5.4
    
     Programming languages that lipsum_cpp.Generator.code() can generate, such
     as C++ and Python.
    """
    Cpp, Python, Rust, C, JavaScript = range(5)

class Format:
    """@brief Types of formats.
      
     @since 0.5.4
      
     Types of formats used in lipsum_cpp.count_paragraphs() and
     lipsum_cpp.convert_format(). In lipsum_cpp.count_paragraphs(), Plain is counting
     plain text, Markdown is counting Markdown or HTML, and HTML is counting
     HTML explicitly.
    """
    Plain, Markdown, HTML, JSON, XML = range(5)

class LipsumString:
    """@brief Wrapper around new/delete C strings

    @since 0.5.4

    A string managed from the C wrapper using lpsm_DeleteString() and new/delete. It automatically
    deletes strings and has conversion to Python strings.
    """
    def __init__(self, ptr:int):
        """@brief Constructor for LipsumString

        @since 0.5.4

        @param self The object pointer.
        @param ptr The raw pointer handle to the string.
        """
        self.__ptr = ptr

    def __str__(self):
        """@brief Convert the LipsumString to a Python str

        @since 0.5.4

        Decode the LipsumString under UTF-8 as a Python str object.

        @param self The object pointer.

        @return str The Python string
        """
        str_at = ctypes.string_at(self.__ptr)
        return str_at.decode("utf-8")

    def __del__(self):
        """@brief Delete the LipsumString.

        @since 0.5.4

        Delete the LipsumString's handle using lpsm_DeleteString.

        @param self The object pointer.
        """
        native_lib.lpsm_DeleteString(self.__ptr)

def generate_default_lipsum_sentence():
    """@brief Generate the beginning Lorem Ipsum sentence.
    
     @since 0.5.4
    
     Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing
     elit."
    
     @return LipsumString The default Lorem Ipsum sentence.
    """
    return LipsumString(native_lib.lpsm_GenerateDefaultLipsumSentence())

def count_words(str_:str):
    """@brief Count the number of words in a string.
    
     @since 0.5.4
    
     Count the number of words in a string using alphanumeric characters,
     hyphens, plus-signs, and apostrophes, excluding words within parentheses.
    
     @param str_ The string inputted.
    
     @return int The number of words.
    """
    return native_lib.lpsm_CountWords(bytes(str_, "utf-8"))

def count_sentence_fragments(str_:str):
    """@brief Count the number of sentence fragments in a string.
    
     @since 0.5.4
    
     Count the number of commas, semicolons, hyphens, and colons in a string,
     excluding usage in Markdown. (i.e. hyphen at start of line, or in
     parentheses)
    
     @param str_ The string inputted.
    
     @return int The number of sentence fragments.
     
    """
    return native_lib.lpsm_CountSentenceFragments(bytes(str_, "utf-8"))

def count_sentences(str_:str):
    """@brief Count the number of sentences in a string.
    
     @since 0.5.4
    
     Count the number of periods, exclamation marks, and question marks in a
     string, ignoring usage in Markdown URLs. (i.e. in parentheses)
    
     @param str_ The string inputted.
    
     @return int The number of sentences.
    """
    return native_lib.lpsm_CountSentences(bytes(str_, "utf-8"))

def count_paragraphs(str_:str, method:int = Format.Plain):
    """@brief Count the number of paragraphs or elements in a string.
    
     @since 0.5.4
    
     Count the number of tab characters in a non-formatted string, double
     newlines in Markdown/HTML strings, and elements in HTML strings.
    
     @param str_ The string inputted.
     @param method The format the string is in. By default non-formatted.
    
     @return int The number of paragraphs. 
    """
    return native_lib.lpsm_CountParagraphs(bytes(str_, "utf-8"), method)

def convert_format(str_:str, format1:int = Format.Plain, format2:int = Format.HTML):
    """@brief Convert a string between two formats.
    
     @since 0.5.4
    
     Attempt a conversion of a string between the two specified formats.
    
     @param str_ The string inputted.
     @param format1 The string's format. By default plain text.
     @param format2 The destination format. By default HTML.
    
     @return str The converted string.
    """
    return LipsumString(native_lib.lpsm_ConvertFormat(bytes(str_, "utf-8"), format1, format2))

class Generator:
    def __init__(self, source_name:str = "lorem", seed = None):
        if seed is None:
            self.__gen = native_lib.lpsm_Generator(bytes(source_name, "utf-8"))
        else:
            self.__gen = native_lib.lpsm_GeneratorSeeded(bytes(source_name, "utf-8"), seed)

    def __del__(self):
        native_lib.lpsm_GeneratorDestroy(self.__gen)

    def load_source(self, source_name:str):
        native_lib.lpsm_Generator_load_source(self.__gen, bytes(source_name, "utf-8"))

    def load_seed(self, seed:int):
        native_lib.lpsm_Generator_load_seed(self.__gen, seed)

    def change_setting(self, setting_name:str, min_:int, max_:int):
        native_lib.lpsm_Generator_change_setting(self.__gen, bytes(source_name, "utf-8"), 
                                                 setting_name, min_, max_)

    def toggle_lazy(self):
        native_lib.lpsm_Generator_toggle_lazy(self.__gen)


    def word(self, num:int = 1):
        return LipsumString(native_lib.lpsm_Generator_word(self.__gen, num))

    def fragment(self):
        return LipsumString(native_lib.lpsm_Generator_fragment(self.__gen))

    def sentence(self, num:int = 1, use_lipsum:bool = True):
        return LipsumString(native_lib.lpsm_Generator_sentence(self.__gen, num, use_lipsum))

    def paragraph(self, num:int = 1, use_lipsum:bool = True):
        return LipsumString(native_lib.lpsm_Generator_paragraph(self.__gen, num, use_lipsum))

    def text(self, use_lipsum:bool = True):
        return LipsumString(native_lib.lpsm_Generator_text(self.__gen, use_lipsum))

    def scramble(self, length:int = 16, min_char:str=" ", max_char:str="~"):
        return LipsumString(native_lib.lpsm_Generator_scramble(self.__gen, 
                                                               bytes(min_char, "utf-8"), 
                                                               bytes(max_char, "utf-8")))

    def url(self):
        return LipsumString(native_lib.lpsm_Generator_url(self.__gen))

    def plain_url(self):
        return LipsumString(native_lib.lpsm_Generator_plain_url(self.__gen))

    def email(self):
        return LipsumString(native_lib.lpsm_Generator_email(self.__gen))

    def slug(self, separator:str = "-"):
        return LipsumString(native_lib.lpsm_Generator_slug(self.__gen, bytes(separator, "utf-8")))

    def case_slug(self, case:int = CaseSlugCase.SnakeCase):
        return LipsumString(native_lib.lpsm_Generator_case_slug(self.__gen, case))

    def code(self, lang:int = CodeLanguage.Python):
        return LipsumString(native_lib.lpsm_Generator_code(self.__gen, lang))

    def ip_addr(self, use_ipv6:bool = False, use_port:bool = False):
        return LipsumString(native_lib.lpsm_Generator_ip_addr(self.__gen, use_ipv6, use_port))

    def phone_number(self):
        return LipsumString(native_lib.lpsm_Generator_phone_number(self.__gen))

    def fmt_paragraph(self, num:int = 1, use_lipsum:bool = True, use_html:bool = False):
        return LipsumString(native_lib.lpsm_Generator_fmt_paragraph(self.__gen, num, use_lipsum, use_html))

    def fmt_text(self, numElements:int = 15, use_html:bool = False):
        return LipsumString(native_lib.lpsm_Generator_fmt_text(self.__gen, numElements, use_html))

    def fmt_header(self, level:int = 1, use_html:bool = False):
        return LipsumString(native_lib.lpsm_Generator_fmt_header(self.__gen, level, use_html))

    def fmt_emphasis(self, is_bold:bool = True, use_html:bool = False):
        return LipsumString(native_lib.lpsm_Generator_fmt_emphasis(self.__gen, is_bold, use_html))

    def fmt_link(self, use_html:bool = False):
        return LipsumString(native_lib.lpsm_Generator_fmt_link(self.__gen, use_html))

    def fmt_list(self, ordered:bool = False, use_html:bool = False):
        return LipsumString(native_lib.lpsm_Generator_fmt_list(self.__gen, ordered, use_html))

    def xml(self, choices:int = 30):
        return LipsumString(native_lib.lpsm_Generator_xml(self.__gen, choices))

    def json(self, max_depth:int = 3, is_object:bool = True):
        return LipsumString(native_lib.lpsm_Generator_json(self.__gen, max_depth, is_object))

    def json_value(self, max_depth:int = 3):
        return LipsumString(native_lib.lpsm_Generator_json_value(self.__gen, max_depth))

    def csv(self):
        return LipsumString(native_lib.lpsm_Generator_csv(self.__gen))


# if __name__ == "__main__":
#     print(native_lib.lpsm_internal_Version__())
#     handle = native_lib.lpsm_Generator(b"lorem")
#     print(native_lib.lpsm_Generator_word(handle, 20))
#     native_lib.lpsm_GeneratorDestroy(handle)
