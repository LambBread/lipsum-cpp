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
    CamelCase, PascalCase, SnakeCase, ShoutyCase, KebabCase, TrainCase = range(6)

class CodeLanguage:
    Cpp, Python, Rust, C, JavaScript = range(5)

class Format:
    Plain, Markdown, HTML, JSON, XML = range(5)

class LipsumString:
    def __init__(self, ptr:int):
        self.__ptr = ptr

    def __str__(self):
        str_at = ctypes.string_at(self.__ptr)
        return str_at.decode("utf-8")

    def __del__(self):
        native_lib.lpsm_DeleteString(self.__ptr)

def generate_default_lipsum_sentence():
    return LipsumString(native_lib.lpsm_GenerateDefaultLipsumSentence())

def count_words(str_:str):
    return native_lib.lpsm_CountWords(bytes(str_, "utf-8"))

def count_sentence_fragments(str_:str):
    return native_lib.lpsm_CountSentenceFragments(bytes(str_, "utf-8"))

def count_sentences(str_:str):
    return native_lib.lpsm_CountSentences(bytes(str_, "utf-8"))

def count_paragraphs(str_:str, method:int = Format.Plain):
    return native_lib.lpsm_CountParagraphs(bytes(str_, "utf-8"), method)

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
