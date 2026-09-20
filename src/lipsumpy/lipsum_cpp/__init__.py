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

     @sa lipsum::CaseSlugCase
    """
    CamelCase, PascalCase, SnakeCase, ShoutyCase, KebabCase, TrainCase = range(6)

class CodeLanguage:
    """@brief Languages used by lipsum_cpp.Generator.code()
    
     @since 0.5.4
    
     Programming languages that lipsum_cpp.Generator.code() can generate, such
     as C++ and Python.

     @sa lipsum::CodeLanguage
    """
    Cpp, Python, Rust, C, JavaScript = range(5)

class Format:
    """@brief Types of formats.
      
     @since 0.5.4
      
     Types of formats used in lipsum_cpp.count_paragraphs() and
     lipsum_cpp.convert_format(). In lipsum_cpp.count_paragraphs(), Plain is counting
     plain text, Markdown is counting Markdown or HTML, and HTML is counting
     HTML explicitly.

     @sa lipsum::Format
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

        @return str The Python string.
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

     @sa lipsum::CountWords
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
     
     @sa lipsum::CountSentenceFragments
    """
    return native_lib.lpsm_CountSentenceFragments(bytes(str_, "utf-8"))

def count_sentences(str_:str):
    """@brief Count the number of sentences in a string.
    
     @since 0.5.4
    
     Count the number of periods, exclamation marks, and question marks in a
     string, ignoring usage in Markdown URLs. (i.e. in parentheses)
    
     @param str_ The string inputted.
    
     @return int The number of sentences.

     @sa lipsum::CountSentences
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

     @sa lipsum::CountParagraphs
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

     @sa lipsum::ConvertFormat
    """
    return LipsumString(native_lib.lpsm_ConvertFormat(bytes(str_, "utf-8"), format1, format2))

class Generator:
    """@brief Constructor for Generator
      
       @since 0.5.4
      
       Load the specified lorem ipsum source and the specified seed.
      
       @param self The object pointer.
       @param path The filepath or name of the lorem ipsum source. By default the default "Lorem ipsum..." source.
       @param seed The seed specified. By default None. (use a random seed)
      
       @sa lipsum::Generator::Generator(const std::string&, int)
       @sa lipsum::Source::load
       
    """
    def __init__(self, source_name:str = "lorem", seed = None):
        if seed is None:
            self.__gen = native_lib.lpsm_Generator(bytes(source_name, "utf-8"))
        else:
            self.__gen = native_lib.lpsm_GeneratorSeeded(bytes(source_name, "utf-8"), seed)

    def __del__(self):
        """@brief Destructor for Generator

        @since 0.5.4

        Delete the Generator's native handle.

        @param self The object pointer.
        """
        native_lib.lpsm_GeneratorDestroy(self.__gen)

    def load_source(self, source_name:str):
        """@brief Reload a source
       
        @since 0.5.4
       
        Reload the specified lorem ipsum source into m_Source. If source_name
        is invalid, it will print a warning and default to the standard
        lorem-ipsum source.
       
        @param self The object pointer.
        @param source_name The filepath or name of the lorem ipsum source.
       
        @sa lipsum::Generator::load_source
        @sa lipsum::Source::load
        """
        native_lib.lpsm_Generator_load_source(self.__gen, bytes(source_name, "utf-8"))

    def load_seed(self, seed:int):
        """@brief Reload a seed
       
        @since 0.5.4
       
        Reload the seed of m_Gen.
       
        @param self The object pointer.
        @param seed The seed specified.

        @sa lipsum::Generator::load_seed
        """
        native_lib.lpsm_Generator_load_seed(self.__gen, seed)

    def change_setting(self, setting_name:str, min_:int, max_:int):
        """@brief Change a setting
       
        @since 0.5.4
       
        Change a setting for generation. Valid setting names include "word",
        "frag", "sent", "para", "point", "wordFmt", "fragFmt", "wordURL",
        "level", "jsonLength", "csvRows", and "csvCols". If an invalid setting name is used, raise
        a warning and ignore.
       
        @param self The object pointer.
        @param setting_name The name of the setting.
        @param min_ The new minimum value of the setting.
        @param max_ The new maximum value of the setting.

        @sa lipsum::Generator::change_setting
        """
        native_lib.lpsm_Generator_change_setting(self.__gen, bytes(setting_name, "utf-8"), 
                                                 min_, max_)

    def toggle_lazy(self):
        """@brief Toggle the lazy flag.
          
        @since 0.5.4
          
        Toggle the lazy flag. If "lazy" is false, set it to true; else, set
        it to false.

        @param self The object pointer.
        
        @sa lipsum::Generator::toggle_lazy
        """
        native_lib.lpsm_Generator_toggle_lazy(self.__gen)


    def word(self, num:int = 1):
        """@brief Generate words.
       
        @since 0.5.4
       
        Generate the specified number of words, separated by spaces. If num
        is negative, print a warning to the console.
       
        @param self The object pointer.
        @param num The number of words. By default 1.
       
        @return LipsumString The random word.

        @sa lipsum::Generator::word
        """
        return LipsumString(native_lib.lpsm_Generator_word(self.__gen, num))

    def fragment(self):
        """@brief Generate a sentence fragment.
       
        @since 0.5.4
       
        Generate a sentence fragment by choosing a random number of words and
        calling word().

        @param self The object pointer.
       
        @return str The random sentence fragment.
        
        @sa lipsum::Generator::fragment()
        """
        return LipsumString(native_lib.lpsm_Generator_fragment(self.__gen))

    def sentence(self, num:int = 1, use_lipsum:bool = True):
        """@brief Generate sentences.
       
        @since 0.5.4
       
        Generate multiple sentences separated by spaces. If num is negative,
        print a warning to the console. If useLipsum is true, make the first
        sentence the default lorem-ipsum sentence.
       
        @param self The object pointer.
        @param num The number of sentences. By default 1.
        @param use_lipsum Whether "Lorem ipsum..." should start the
        sentence(s). By default true.
       
        @return LipsumString The random sentence(s).
       
        @sa lipsum::Generator::single_sentence(const lpsm::ArgVec2&, const
        lpsm::ArgVec2&)
        @sa lipsum::Generator::sentence()
        
        """
        return LipsumString(native_lib.lpsm_Generator_sentence(self.__gen, num, use_lipsum))

    def paragraph(self, num:int = 1, use_lipsum:bool = True):
        """@brief Generate paragraphs.
       
        @since 0.5.4
       
        Generate multiple paragraphs. If num is negative, print a warning to
        the console.
       
        @param self The object pointer.
        @param num The number of paragraphs. By default 1.
        @param use_lipsum Whether "Lorem ipsum..." should start the
        paragraph(s). By default true.
       
        @return LipsumString The random paragraph(s).
       
        @sa lipsum::Generator::single_paragraph(bool)
        @sa lipsum::Generator::paragraph
        
        """
        return LipsumString(native_lib.lpsm_Generator_paragraph(self.__gen, num, use_lipsum))

    def text(self, use_lipsum:bool = True):
        """@brief Generate a random number of random paragraphs.
       
        @since 0.5.4
       
        Generate a random number of random paragraphs by choosing a random
        number of paragraphs and calling paragraph().
       
        @param self The object pointer.
        @param use_lipsum Whether "Lorem ipsum..." should start the
        paragraph(s). By default true.
       
        @return LipsumString The random text.

        @sa lipsum::Generator::text
        
        """
        return LipsumString(native_lib.lpsm_Generator_text(self.__gen, use_lipsum))

    def scramble(self, length:int = 16, min_char:str=" ", max_char:str="~"):
        """@brief Generate a random character scramble.
       
        @since 0.5.4
       
        Generate a random string of text with random characters. If length is
        negative, print a warning to the console. Add length number of random
        characters from min_char to max_char to the string.
       
        @param self The object pointer.
        @param length The number of characters. By default 16.
        @param min_char The lowest-valued ASCII character that can appear. By
        default a space.
        @param max_char The highest-valued ASCII character than can appear. By
        default a tilde.
       
        @return LipsumString The character scramble.
        
        @sa lipsum::Generator::scramble
        """
        return LipsumString(native_lib.lpsm_Generator_scramble(self.__gen, 
                                                               bytes(min_char, "utf-8"), 
                                                               bytes(max_char, "utf-8")))

    def url(self):
        """@brief Generate a URL.
       
        @since 0.5.4
       
        Generate a URL starting in https://, followed by a plain url,
        followed by a slash and a random HTML id as
        a slug separated by hyphens.
       
        @param self The object pointer.

        @return LipsumString The URL.
       
        @sa lipsum::Generator::plain_url
        @sa lipsum::Generator::url
        """
        return LipsumString(native_lib.lpsm_Generator_url(self.__gen))

    def plain_url(self):
        """@brief Generate a plain URL.
       
        @since 0.5.4
       
        Generate a URL with "lpsmcpp-" and a random word followed by a random
        TLD.

        @param self The object pointer.
       
        @return LipsumString The plain URL.
        
        @sa lipsum::Generator::plain_url
        """
        return LipsumString(native_lib.lpsm_Generator_plain_url(self.__gen))

    def email(self):
        """@brief Generate an email.
       
        @since 0.5.4
       
        Generate two words separated by a period, with an at-sign and a plain
        url.

        @param self The object pointer.
       
        @return LipsumString The email.

        @sa lipsum::Generator::email
        """
        return LipsumString(native_lib.lpsm_Generator_email(self.__gen))

    def slug(self, separator:str = "-"):
        """@brief Generate a slug.
       
        @since 0.5.4
       
        Generate a sentence fragment with the spaces replaced
        with the specified separator character.
       
        @param self The object pointer.
        @param separator The separator character. By default a hyphen.
       
        @return LipsumString The slug.

        @sa lipsum::Generator::slug
        """
        return LipsumString(native_lib.lpsm_Generator_slug(self.__gen, bytes(separator, "utf-8")))

    def case_slug(self, case:int = CaseSlugCase.SnakeCase):
        """@brief Generate a case slug.
       
        @since 0.5.4
       
        Generate a case slug in the specified case, e.g. camel case, snake
        case, etc.
       
        @param self The object pointer.
        @param case The case. By default camel case.
       
        @return LipsumString The case slug.

        @sa lipsum::Generator::case_slug
        """
        return LipsumString(native_lib.lpsm_Generator_case_slug(self.__gen, case))

    def code(self, lang:int = CodeLanguage.Python):
        """@brief Generate a code block.
       
        @since 0.5.4
       
        Generate a pseudo main function in the specified programming
        language.
       
        @param self The object pointer.
        @param lang The language chosen. By default Python.
       
        @return LipsumString The code block.

        @sa lipsum::Generator::code 
        """
        return LipsumString(native_lib.lpsm_Generator_code(self.__gen, lang))

    def ip_addr(self, use_ipv6:bool = False, use_port:bool = False):
        """
        
        @brief Generate an IP address.
       
        @since 0.5.4
       
        Generate an IPv4 or IPv6 IP address, optionally with a port.
        Start by choosing a port. If useIpv6 is false, generate 4 numbers
        from 0-255 and fill them into the format x.x.x.x, or x.x.x.x:port.
        If useIpv6 is true, generate 8 hexadecimal numbers from 0-65536
        and fill them into the format x:x:x:x:x:x:x:x, or
        [x:x:x:x:x:x:x:x]:port.
       
        @param self The object pointer.
        @param use_ipv6 Whether to use IPv6. By default false (IPv4).
        @param use_port Whether to add a port. By default false.
       
        @return LipsumString The IP address.

        @sa lipsum::Generator::ip_addr
        """
        return LipsumString(native_lib.lpsm_Generator_ip_addr(self.__gen, use_ipv6, use_port))

    def phone_number(self):
        """@brief Generate a phone number.
       
        @since 0.5.4
       
        Generate a phone number in the format "(+1) xxx-xxx-xxxx".

        @param self The object pointer.
       
        @return LipsumString The phone number.
        
        @sa lipsum::Generator::phone_number
        """
        return LipsumString(native_lib.lpsm_Generator_phone_number(self.__gen))

    def fmt_paragraph(self, num:int = 1, use_lipsum:bool = True, use_html:bool = False):
        """@brief Generate Markdown or HTML paragraphs.
        
         @since 0.5.4
        
         Generate multiple paragraphs in Markdown or HTML format. If num is negative, 
         print a warning to the console. If doing a minimum build, return an empty string.
        
         @param self The object pointer.
         @param num The number of paragraphs. By default 1.
         @param use_lipsum Whether "Lorem ipsum..." should start the paragraph.
         By default true.
         @param use_html Whether HTML should be outputted instead of Markdown.
         By default false.
        
         @return LipsumString The random Markdown paragraphs.
         
         @sa lipsum::Generator::fmt_paragraph
        """
        return LipsumString(native_lib.lpsm_Generator_fmt_paragraph(self.__gen, num, use_lipsum, use_html))

    def fmt_text(self, numElements:int = 15, use_html:bool = False):
        """@brief Generate a Markdown or HTML document.
       
        @since 0.5.4
       
        Generate a document in Markdown or HTML format. If numElements is negative, print a warning to the
        console. If numElements is greater than or equal to 1, add a heading.
        If numElements is greater than or equal to 2, add a formatted
        paragraph. For every numElements beyond 2, pick a random number from
        0 to 2. If it is equal to 1 and the last roll resulted in 1, or there
        is only 3 total elements, set it to 0. This is meant to stop headings
        after each other and headings at the end of a document. Choose if a
        list will be ordered, and if the random number is equal to 0, add a
        formatted paragraph. If the random number is equal to 1, add a
        heading. If it is equal to 2, add a list. If doing a minimum build,
        return an empty string.
       
        @param self The object pointer.
        @param numElements The number of elements (paragraph, list, heading)
        in the document. By default 15.
        @param use_html Whether HTML should be outputted instead of Markdown.
        By default false.
       
        @return std::string The random Markdown document.
        
        @sa lipsum::Generator::fmt_text
        """
        return LipsumString(native_lib.lpsm_Generator_fmt_text(self.__gen, numElements, use_html))

    def fmt_header(self, level:int = 1, use_html:bool = False):
        """@brief Generate a Markdown or HTML header.
       
        @since 0.5.4
       
        Generate a header in Markdown or HTML format. If level is less than 1
        or greater than 6, print a warning to the console. If useHtml is
        true, start an HTML heading tag at the specified level. If useHtml is
        false, start a Markdown heading at the specified level. Append a
        sentence fragment with the first letter capitalized, close the HTML
        tag and append two newlines. If doing
        a minimum build, return an empty string.
       
        @param self The object pointer.
        @param level The level of the heading. By default 1.
        @param use_html Whether HTML should be outputted instead of Markdown.
        By default false.
       
        @return LipsumString The random Markdown header.
        
        @sa lipsum::Generator::fmt_header
        """
        return LipsumString(native_lib.lpsm_Generator_fmt_header(self.__gen, level, use_html))

    def fmt_emphasis(self, is_bold:bool = True, use_html:bool = False):
        """@brief Generate an emphasized Markdown or HTML sentence.
         
          @since 0.5.4
         
          Generate a bold or italic sentence in Markdown or HTML format that is
          either bold or italic. If is_bold is true, make the sentence bold;
          else italic. If use_html is true, use HTML bold or italic tags. If
          useHtml is false, use Markdown bold or italic specifiers. If doing a minimum build, 
          return an empty string.
         
          @param self The object pointer.
          @param is_bold Whether the sentence is bold or italic. By default
          true. (bold)
          @param use_html Whether HTML should be outputted instead of Markdown.
          By default false.
         
          @return LipsumString The random emphasized Markdown sentence.

          @sa lipsum:::Generator::fmt_emphasis
        """
        return LipsumString(native_lib.lpsm_Generator_fmt_emphasis(self.__gen, is_bold, use_html))

    def fmt_link(self, use_html:bool = False):
        """
         @brief Generate a Markdown or HTML link.
        
         @since 0.5.4
        
         Generate a link in Markdown or HTML format. Generate a random
         sentence and random URL; if use_html is false, return an opening
         square bracket, the sentence, a closing square bracket and opening
         parenthesis, the URL, and a closing parenthesis to form a Markdown
         URL. If use_html is true, return an HTML \<a\> tag linking to the url
         with the sentence. If doing a minimum build, return an empty string.
        
         @param self The object pointer.
         @param use_html Whether HTML should be outputted instead of Markdown.
         By default false.
        
         @return LipsumString The random Markdown link.
        
         @sa lipsum::Generator::url
         @sa lipsum::Generator::fmt_link
        """
        return LipsumString(native_lib.lpsm_Generator_fmt_link(self.__gen, use_html))

    def fmt_list(self, ordered:bool = False, use_html:bool = False):
        """
        @brief Generate a Markdown or HTML list.
       
        @since 0.5.4
       
        Generate an ordered or unordered list in Markdown or HTML format. It
        does this by picking a random number of points, and if use_html is
        true, start an HTML list tag. Repeat the number of points: if use_html
        is false and ordered is true, append the current index and a period;
        if use_html is false and ordered is false, append a hyphen and a
        space. If useHtml is true, start an \<li\> HTML tag. Append a random
        sentence, and append a newline or close the HTML tag. End the loop,
        and close the HTML list tag. If doing a minimum build, return an
        empty string.
       
        @param self The object pointer.
        @param ordered Whether the list is ordered. By default false.
        @param use_html Whether HTML should be outputted instead of Markdown.
        By default false.
       
        @return LipsumString The random Markdown list.

        @sa lipsum::Generator::fmt_list
        """
        return LipsumString(native_lib.lpsm_Generator_fmt_list(self.__gen, ordered, use_html))

    def xml(self, choices:int = 30):
        """
        @brief Generate an XML document.
       
        @since 0.5.4
       
        Generate a document in XML format. It does this by starting the XML
        prolog, choosing the root element, and starting it. It then repeats
        choices times: it generates a random number from 0 to 2. If it is 0,
        start an XML tag with a random element with optionally an attribute,
        and also add it to the tag stack. If the number is 1, add a closed
        element with a random sentence inside. If the number is 2, close the
        previously opened tag if possible. Finally, end the loop and close
        all remaining tags in the tag stack, and close the root element. If
        doing a minimum build, return an empty string.
       
        @param self The object pointer.
        @param choices The number of choices (start element, end element, add
        data element) that are made. By default 30.
       
        @return LipsumString The random XML document.

        @sa lipsum::Generator::xml
        """
        return LipsumString(native_lib.lpsm_Generator_xml(self.__gen, choices))

    def json(self, max_depth:int = 3, is_object:bool = True):
        """
        @brief Generate a JSON object or array.
       
        @since 0.5.4
       
        Generate an object or array in JSON format. If doing a minimum build,
        return an empty string.
       
        @param self The object pointer.
        @param max_depth The maximum level of recursion. By default 3.
        @param is_object Whether to output an object (true) or an array
        (false). By default true.
       
        @return LipsumString The random JSON object or array.

        @sa lipsum::Generator::json
        """
        return LipsumString(native_lib.lpsm_Generator_json(self.__gen, max_depth, is_object))

    def json_value(self, max_depth:int = 3):
        """
        @brief Generate a JSON value.
       
        @since 0.5.4
       
        Generate an object, array, number, string, boolean, or null in JSON
        format. If max_depth is greater than or equal to 50, print a warning.
        If doing a minimum build, return an empty string.
       
        @param self The object pointer.
        @param max_depth The maximum level of recursion. By default 3.
       
        @return LipsumString The random JSON value.

        @sa lipsum::Generator::json_value
        """
        return LipsumString(native_lib.lpsm_Generator_json_value(self.__gen, max_depth))

    def csv(self):
        """
        @brief Generate a CSV document.
          
        @since 0.5.4
          
        Generate a CSV document. It does this by choosing a random number of
        rows and columns, and selecting the types of each column out of the
        following: integers, floating point values, sentences, words, emails,
        and scrambles. It sets up the top row, and then for every row, fill
        each column.

        @param self The object pointer.
          
        @return LipsumString The CSV document.

        @sa lipsum::Generator::csv
        """
        return LipsumString(native_lib.lpsm_Generator_csv(self.__gen))


# if __name__ == "__main__":
#     print(native_lib.lpsm_internal_Version__())
#     handle = native_lib.lpsm_Generator(b"lorem")
#     print(native_lib.lpsm_Generator_word(handle, 20))
#     native_lib.lpsm_GeneratorDestroy(handle)
