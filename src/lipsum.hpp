/**
 * @file lipsum.hpp
 *
 * @brief Main header of lipsum-cpp
 *
 * This contains the declarations of functions as well as definitions
 * if LIPSUM_IMPLEMENTATION is defined.
 *
 * @author LambBread from github.com
 *
 * @example GenerateDefaultLipsumSentence.cpp
 * @example GenerateParagraph.cpp
 * @example GenerateParagraphs.cpp
 * @example GenerateSentence.cpp
 * @example GenerateSentenceFragment.cpp
 * @example GenerateSentences.cpp
 * @example GenerateWord.cpp
 * @example Markdown.cpp
 * @example FuncsX.cpp
 * @example Basic.cpp
 * @example GenerateWords.cpp
 */

#pragma once

/**
 * @brief The current version of lipsum-cpp.
 *
 * This macro stores the current version of lipsum-cpp.
 */
#define LIPSUM_CPP_VERSION "0.3.0"

#ifndef __cplusplus
#    error lipsum.hpp only supports C++, did you mean lipsum.h?
#endif

/**
 * @brief Macro for shared libraries
 *
 * This macro helps with shared libraries on Windows by exporting
 * or importing functions.
 */
#ifdef LIPSUM_BUILD_SHARED
#    ifdef _WIN32
#        ifdef LIPSUM_EXPORT_SHARED
#            define LIPSUM_API __declspec(dllexport)
#        else
#            define LIPSUM_API __declspec(dllimport)
#        endif
#    else
#        define LIPSUM_API
#    endif
#else
#    define LIPSUM_API
#endif

#include <cctype>
#include <random>
#include <sstream>
#include <string>
#include <vector>
/**
 * @namespace lipsum
 *
 * @brief This is the main namespace of lipsum-cpp.
 *
 * This namespace contains all the code for the C++ usage of lipsum-cpp.
 */
namespace lipsum
{
    /**
     * @namespace lipsum::internal
     *
     * @brief This namespace contains functions only used internally by other
     * functions.
     *
     * This namespace's functions are not intended for public use and are
     * not exposed in the C wrapper.
     */
    namespace internal
    {
        LIPSUM_API std::string HandleHTMLEntity(const std::string& str);
        LIPSUM_API int         RandomNumber(int min, int max);

        template <typename T> std::string ToString(const T& x)
        {
            std::stringstream ss;
            ss << x;
            return ss.str();
        }
    } // namespace internal

    /**
     * @brief Store data for inputting into functions.
     *
     * This struct stores values min and max, which
     * are intended to be inputted into functions as arguments.
     * Not exposed in the C wrapper.
     */
    struct LIPSUM_API ArgVec2
    {
        /**
         * @brief Constructor for ArgVec2
         *
         * @param min Value to enter into this->min
         * @param max Value to enter into this->max
         */
        ArgVec2(int min, int max);

        /**
         * @brief Return a number between min and max.
         *
         * This function returns a random value between min and max.
         *
         * @return int The random number.
         */
        int Roll() const;

        int min; ///< The minimum value
        int max; ///< The maximum value
    };

    /**
     * @brief OOP layer over lipsum-cpp
     *
     * This provides a more user-friendly object-oriented layer over lipsum-cpp.
     * It uses mainly default arguments. Unlike most of the codebase which uses
     * PascalCase, the functions in this class use snake_case.
     */
    class LIPSUM_API Generator
    {
    public:
        /**
         * @brief Generate words.
         *
         * This function generates multiple words.
         *
         * @param num The number of words. By default 1.
         *
         * @return std::string The random word.
         */
        std::string word(int num = 1);

        /**
         * @brief Generate sentences.
         *
         * This function generates multiple sentences with default arguments.
         *
         * @param num The number of sentences. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * sentence(s). By default true.
         *
         * @return std::string The random sentence(s).
         */
        std::string sentence(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate a sentence fragment.
         *
         * This function generates a sentence fragment with default arguments.
         *
         * @return std::string The random sentence fragment.
         */
        std::string sentence_fragment();

        /**
         * @brief Generate paragraphs.
         *
         * This function generates multiple paragraphs with default arguments.
         *
         * @param num The number of paragraphs. By default 1.
         * @param useLipsum Whether "Lorem ipsum..." should start the
         * paragraph(s). By default true.
         *
         * @return std::string The random paragraph(s).
         */
        std::string paragraph(int num = 1, bool useLipsum = true);

        /**
         * @brief Generate a Markdown paragraph.
         *
         * This function generates a paragraph in Markdown format with default
         * arguments.
         *
         * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
         * By default true.
         *
         * @return std::string The random Markdown paragraph.
         */
        std::string md_paragraph(bool useLipsum = true);

        /**
         * @brief Generate a Markdown document.
         *
         * This function generates a document in Markdown format with default
         * arguments.
         *
         * @param numElements The number of elements (paragraph, list, heading)
         * in the document. By default 15.
         *
         * @return std::string The random Markdown document.
         */
        std::string md_text(int numElements = 15);
    };

    /**
     * @brief Generate a random word.
     *
     * This function generates a random word from a predefined list.
     *
     * @return std::string The random word.
     */
    LIPSUM_API std::string GenerateWord();

    /**
     * @brief Generate a specified number of random words.
     *
     * This function generates a sentence fragment with exactly wordCount words.
     *
     * @param wordCount The number of words. By default 6.
     *
     * @return std::string The random words.
     */
    LIPSUM_API std::string GenerateWords(int wordCount = 6);

    /**
     * @brief Generate a fragment of a sentence without punctuation.
     *
     * This function generates a fragment of a sentence, without punctuation
     * inside.
     *
     * @param word The minimum and maximum possible number of words in a
     * fragment. By default 4 to 9.
     *
     * @return std::string The random sentence fragment.
     */
    LIPSUM_API std::string
               GenerateSentenceFragment(const ArgVec2& word = ArgVec2(4, 9));

    /**
     * @brief Generate a fragment of a sentence without punctuation.
     *
     * @xovload
     *
     * @param minWord Minimum possible number of words in a sentence fragment.
     * By default 4.
     * @param maxWord Maximum possible number of words in a sentence fragment.
     * By default 9.
     *
     * @return std::string The random sentence fragment.
     */
    LIPSUM_API std::string GenerateSentenceFragmentX(int minWord = 4,
                                                     int maxWord = 9);

    /**
     * @brief Generate a random sentence.
     *
     * This function generates a sentence starting with a capital letter
     * and ending with a period, often containing commas, semicolons, and
     * dashes.
     *
     * @return std::string The random sentence.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence. By default 1 to 3.
     */
    LIPSUM_API std::string GenerateSentence(const ArgVec2& word = ArgVec2(4, 9),
                                            const ArgVec2& frag = ArgVec2(1,
                                                                          3));

    /**
     * @brief Generate a random sentence.
     *
     * @xovload
     *
     * @param minWord Minimum possible number of words in a sentence fragment.
     * By default 4.
     * @param maxWord Maximum possible number of words in a sentence fragment.
     * By default 9.
     * @param minFrag Minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag Maximum possible number of sentence fragments in a
     * sentence. By default 3.
     *
     * @return std::string The random sentence.
     */
    LIPSUM_API std::string GenerateSentenceX(int minWord = 4,
                                             int maxWord = 9,
                                             int minFrag = 1,
                                             int maxFrag = 3);

    /**
     * @brief Generate a random paragraph.
     *
     * This function generates a random paragraph starting with a tab character
     * and ending in a line break, with each sentence separated by a space.
     *
     * @return std::string The random paragraph.
     *
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph. By default 5 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the paragraph. By default true.
     */
    LIPSUM_API std::string
               GenerateParagraph(const ArgVec2& word      = ArgVec2(4, 9),
                                 const ArgVec2& frag      = ArgVec2(1, 3),
                                 const ArgVec2& sent      = ArgVec2(5, 8),
                                 bool           useLipsum = true);

    /**
     * @brief Generate a random paragraph.
     *
     * @xovload
     *
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param minSent The minimum possible number of sentences in the paragraph.
     * By default 5.
     * @param maxSent The maximum possible number of sentences in the paragraph.
     * By default 8.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the paragraph. By default true.
     *
     * @return std::string The random paragraph.
     */
    LIPSUM_API std::string GenerateParagraphX(int  minWord   = 4,
                                              int  maxWord   = 9,
                                              int  minFrag   = 1,
                                              int  maxFrag   = 3,
                                              int  minSent   = 5,
                                              int  maxSent   = 8,
                                              bool useLipsum = true);

    /**
     * @brief Generate several random paragraphs at once.
     *
     * This function generates several random paragraphs, each separated by a
     * line break. Formerly known as lipsum::GenerateParagraphList().
     *
     * @return std::string The random paragraphs.
     *
     * @param paraCount The number of paragraphs. By default 5.
     * @param word The minimum and maximum total number of words in a sentence
     * fragment. By default 4 to 9.
     * @param frag The minimum and maximum total number of sentence fragments in
     * a sentence. By default 1 to 3.
     * @param sent The minimum and maximum total number of sentences in a
     * paragraph. By default 5 to 8.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the first paragraph. By default true.
     */
    LIPSUM_API std::string
               GenerateParagraphs(int            paraCount = 5,
                                  const ArgVec2& word      = ArgVec2(4, 9),
                                  const ArgVec2& frag      = ArgVec2(1, 3),
                                  const ArgVec2& sent      = ArgVec2(5, 8),
                                  bool           useLipsum = true);

    /**
     * @brief Generate several random paragraphs at once.
     *
     * @xovload
     *
     * @param paraCount The number of paragraphs. By default 5.
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param minSent The minimum possible number of sentences in a paragraph.
     * By default 5.
     * @param maxSent The maximum possible number of sentences in a paragraph.
     * By default 8.
     * @param useLipsum Whether the default "Lorem ipsum..." text should start
     * the first paragraph. By default true.
     *
     * @return std::string The random paragraphs.
     */
    LIPSUM_API std::string GenerateParagraphsX(int  paraCount = 5,
                                               int  minWord   = 4,
                                               int  maxWord   = 9,
                                               int  minFrag   = 1,
                                               int  maxFrag   = 3,
                                               int  minSent   = 5,
                                               int  maxSent   = 8,
                                               bool useLipsum = true);

    /**
     * @brief Generate the beginning Lorem Ipsum sentence.
     *
     * Returns the sentence "Lorem ipsum dolor sit amet, consectetur adipiscing
     * elit."
     *
     * @return std::string The default Lorem Ipsum sentence.
     */
    LIPSUM_API std::string GenerateDefaultLipsumSentence();

    /**
     * @brief Generate multiple random sentences at once.
     *
     * Generate multiple random sentences separated with spaces. Does not add a
     * tab character before the sentences nor a line break after.
     *
     * @return std::string Returns the random sentences.
     *
     * @param sentCount The number of sentences. By default 6.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param useLipsum Whether the default "Lorem ipsum..." sentence should be
     * the first sentence. By default true.
     */
    LIPSUM_API std::string
               GenerateSentences(int            sentCount = 6,
                                 const ArgVec2& word      = ArgVec2(4, 9),
                                 const ArgVec2& frag      = ArgVec2(1, 3),
                                 bool           useLipsum = true);

    /**
     * @brief Generate multiple random sentences at once.
     *
     * @xovload
     *
     * @param sentCount The number of sentences. By default 6.
     * @param minWord The minimum possible number of words in a sentence
     * fragment. By default 4.
     * @param maxWord The maximum possible number of words in a sentence
     * fragment. By default 9.
     * @param minFrag The minimum possible number of sentence fragments in a
     * sentence. By default 1.
     * @param maxFrag The maximum possible number of sentence fragments in a
     * sentence. By default 3.
     * @param useLipsum Whether the default "Lorem ipsum..." sentence should be
     * the first sentence. By default true.
     */
    LIPSUM_API std::string GenerateSentencesX(int  sentCount = 6,
                                              int  minWord   = 4,
                                              int  maxWord   = 9,
                                              int  minFrag   = 1,
                                              int  maxFrag   = 3,
                                              bool useLipsum = true);

    /**
     * @brief Turn a string into HTML paragraph tags.
     *
     * @deprecated Use a Markdown parser instead.
     *
     * Add &lt;p&gt; and &lt;/p&gt; around the paragraphs and
     * handle HTML entities like &amp;, &lt;, &gt;, etc. This function is
     * deprecated.
     *
     * @return std::string The HTML-ified string.
     *
     * @param str The string inputted.
     */
    LIPSUM_API [[deprecated("Use a Markdown parser")]] std::string
    HTMLify(const std::string& str);

    /**
     * @overload
     *
     * @deprecated Use a Markdown parser instead.
     *
     * Turn a string into HTML paragraph tags specified by a C-style string.
     * This function is deprecated.
     *
     * @param str The string inputted.
     *
     * @return std::string The HTML-ified string.
     */
    LIPSUM_API [[deprecated("Use a Markdown parser")]] std::string
    HTMLify(const char* str);

    /**
     * @brief Count the number of sentences in a string.
     *
     * Count the number of periods in a string, ignoring usage in Markdown URLs.
     *
     * @param str The string inputted.
     *
     * @return int The number of sentences.
     */
    LIPSUM_API int CountSentences(const std::string& str);

    /**
     * @brief Generate a random Markdown header.
     *
     * Generate a random Markdown header. This function is not exposed in the C
     * wrapper.
     *
     * @param level The level of the heading. By default 1.
     * @param word The minimum and maximum possible number of words in the
     * heading. By default 2 to 5.
     *
     * @return std::string The random heading.
     */
    LIPSUM_API std::string
    GenerateMarkdownHeader(int level = 1, const ArgVec2& word = ArgVec2(2, 5));

    /**
     * @brief Generate a random emphasized sentence.
     *
     * Generate a random sentence in Markdown format that is either bold or
     * italic. This function is not exposed in the C wrapper.
     *
     * @param isBold Whether the sentence is bold or italic. By default true.
     * (bold)
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence. By default 1 to 2.
     *
     * @return std::string The random emphasized sentence.
     */
    LIPSUM_API std::string
               GenerateMarkdownEmphasis(bool           isBold = true,
                                        const ArgVec2& word   = ArgVec2(4, 8),
                                        const ArgVec2& frag   = ArgVec2(1, 2));

    /**
     * @brief Generate a random Markdown link.
     *
     * Generate a random link in Markdown format. This function is not exposed
     * in the C wrapper.
     *
     * @param url The URL to base the link off of. By default
     * https://example.com/.
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in the sentence. By default 1 to 2.
     * @param wordURL The minimum and maximum possible number of words at the
     * end of the URL. By default 2 to 5.
     *
     * @return std::string The random link.
     */
    LIPSUM_API std::string GenerateMarkdownLink(
            const std::string& url     = std::string("https://example.com/"),
            const ArgVec2&     word    = ArgVec2(4, 8),
            const ArgVec2&     frag    = ArgVec2(1, 2),
            const ArgVec2&     wordURL = ArgVec2(2, 5));

    /**
     * @brief Generate a random Markdown list.
     *
     * Generate a random ordered or unordered list in Markdown format. This
     * function is not exposed in the C wrapper.
     *
     * @param ordered Whether the list is ordered or unordered. By default
     * false. (unordered)
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 8.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a point. By default 1 to 2.
     * @param point The minimum and maximum possible number of points in the
     * list. By default 3 to 5.
     *
     * @return std::string The random Markdown list.
     */
    LIPSUM_API std::string
               GenerateMarkdownList(bool           ordered = false,
                                    const ArgVec2& word    = ArgVec2(4, 8),
                                    const ArgVec2& frag    = ArgVec2(1, 2),
                                    const ArgVec2& point   = ArgVec2(3, 5));

    /**
     * @brief Generate a random formatted paragraph.
     *
     * Generate a paragraph in Markdown format with bold, italic, and links.
     * This function is not exposed in the C wrapper.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param sent The minimum and maximum possible number of sentences in the
     * paragraph. By default 5 to 8.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence. By default 4 to 8.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence. By default 1 to 2.
     * @param wordLink The minimum and maximum possible number of words in a
     * link URL. By default 2 to 5.
     * @param linkURL The URL to base links off of. By default
     * https://example.com/.
     * @param useLipsum Whether "Lorem ipsum..." should start the paragraph.
     *
     * @return std::string The random paragraph.
     */
    LIPSUM_API std::string GenerateMarkdownParagraph(
            const ArgVec2&     word      = ArgVec2(4, 9),
            const ArgVec2&     frag      = ArgVec2(1, 3),
            const ArgVec2&     sent      = ArgVec2(5, 8),
            const ArgVec2&     wordFmt   = ArgVec2(4, 8),
            const ArgVec2&     fragFmt   = ArgVec2(1, 2),
            const ArgVec2&     wordLink  = ArgVec2(2, 5),
            const std::string& linkURL   = std::string("https://example.com/"),
            bool               useLipsum = true);

    /**
     * @brief Generate a random Markdown document.
     *
     * Generate a random document in Markdown format.
     *
     * @param word The minimum and maximum possible number of words in a
     * sentence fragment. By default 4 to 9.
     * @param frag The minimum and maximum possible number of sentence fragments
     * in a sentence. By default 1 to 3.
     * @param sent The minimum and maximum possible number of sentences in a
     * paragraph. By default 5 to 8.
     * @param point The minimum and maximum possible number of points in a list.
     * By default 3 to 5.
     * @param wordFmt The minimum and maximum possible number of words in a
     * sentence fragment in a formatted sentence. By default 4 to 8.
     * @param fragFmt The minimum and maximum possible number of sentence
     * fragments in a formatted sentence. By default 1 to 2.
     * @param wordHead The minimum and maximum possible number of words in a
     * link URL or heading. By default 2 to 5.
     * @param level The minimum and maximum possible heading levels, excluding
     * the main heading. By default 2 to 4.
     * @param linkURL The URL to base links off of. By default
     * https://example.com/.
     * @param numElements The number of paragraphs, headings, and lists total.
     * By default 15.
     *
     * @return std::string The random Markdown document.
     */
    LIPSUM_API std::string GenerateMarkdownText(
            const ArgVec2&     word     = ArgVec2(4, 9),
            const ArgVec2&     frag     = ArgVec2(1, 3),
            const ArgVec2&     sent     = ArgVec2(5, 8),
            const ArgVec2&     point    = ArgVec2(3, 5),
            const ArgVec2&     wordFmt  = ArgVec2(4, 8),
            const ArgVec2&     fragFmt  = ArgVec2(1, 2),
            const ArgVec2&     wordHead = ArgVec2(2, 5),
            const ArgVec2&     level    = ArgVec2(2, 4),
            const std::string& linkURL  = std::string("https://example.com/"),
            int                numElements = 15);
} // namespace lipsum

/// Alias for namespace lipsum
namespace lpsm = lipsum;

#ifdef LIPSUM_IMPLEMENTATION

std::string lpsm::Generator::md_paragraph(bool useLipsum)
{
    return lpsm::GenerateMarkdownParagraph(ArgVec2(4, 9),
                                           ArgVec2(1, 3),
                                           ArgVec2(5, 8),
                                           ArgVec2(4, 8),
                                           ArgVec2(1, 2),
                                           ArgVec2(2, 5),
                                           std::string("https://example.com/"),
                                           useLipsum);
}

std::string lpsm::Generator::md_text(int numElements)
{
    return lpsm::GenerateMarkdownText(ArgVec2(4, 9),
                                      ArgVec2(1, 3),
                                      ArgVec2(5, 8),
                                      ArgVec2(3, 5),
                                      ArgVec2(4, 8),
                                      ArgVec2(1, 2),
                                      ArgVec2(2, 5),
                                      ArgVec2(2, 4),
                                      std::string("https://example.com/"),
                                      numElements);
}

std::string lpsm::GenerateMarkdownText(const ArgVec2&     word,
                                       const ArgVec2&     frag,
                                       const ArgVec2&     sent,
                                       const ArgVec2&     point,
                                       const ArgVec2&     wordFmt,
                                       const ArgVec2&     fragFmt,
                                       const ArgVec2&     wordHead,
                                       const ArgVec2&     level,
                                       const std::string& linkURL,
                                       int                numElements)
{
    std::string ret;
    ret += lpsm::GenerateMarkdownHeader(1, wordHead);
    ret += lpsm::GenerateMarkdownParagraph(word,
                                           frag,
                                           sent,
                                           wordFmt,
                                           fragFmt,
                                           wordHead,
                                           linkURL,
                                           false);
    numElements -= 2;
    int           rand;
    bool          ordered;
    lpsm::ArgVec2 elem  = ArgVec2(0, 2);
    lpsm::ArgVec2 order = ArgVec2(0, 1);
    while (numElements > 0)
    {
        rand    = elem.Roll();
        ordered = static_cast<bool>(order.Roll());
        switch (rand)
        {
            case 0:
            {
                ret += lpsm::GenerateMarkdownParagraph(word,
                                                       frag,
                                                       sent,
                                                       wordFmt,
                                                       fragFmt,
                                                       wordHead,
                                                       linkURL,
                                                       false);
                break;
            }
            case 1:
            {
                ret += lpsm::GenerateMarkdownHeader(level.Roll(), wordHead);
                break;
            }
            case 2:
            {
                ret += lpsm::GenerateMarkdownList(ordered,
                                                  wordFmt,
                                                  fragFmt,
                                                  point);
                break;
            }
        }
        --numElements;
    }
    return ret;
}

std::string lpsm::GenerateMarkdownList(bool                 ordered,
                                       const lpsm::ArgVec2& word,
                                       const lpsm::ArgVec2& frag,
                                       const lpsm::ArgVec2& point)
{
    std::string ret;
    int         points = point.Roll();
    for (int i = 0; i < points; ++i)
    {
        if (ordered)
        {
            ret += lpsm::internal::ToString(i + 1) += ". ";
        }
        else
        {
            ret += "- ";
        }
        ret += lpsm::GenerateSentence(word, frag) += "\n";
    }
    ret += "\n";
    return ret;
}

int lpsm::CountSentences(const std::string& str)
{
    int res    = 0;
    int urlNum = 0;
    for (const char& c : str)
    {
        if (c == '(')
        {
            ++urlNum;
        }
        if (c == ')')
        {
            --urlNum;
        }
        if (c == '.' && urlNum == 0)
        {
            ++res;
        }
    }
    return res;
}

std::string lpsm::GenerateMarkdownParagraph(const lpsm::ArgVec2& word,
                                            const lpsm::ArgVec2& frag,
                                            const lpsm::ArgVec2& sent,
                                            const ArgVec2&       wordFmt,
                                            const ArgVec2&       fragFmt,
                                            const ArgVec2&       wordLink,
                                            const std::string&   linkURL,
                                            bool                 useLipsum)
{
    std::string   ret;
    int           sents = sent.Roll();
    int           fmtRoll;
    bool          addLink;
    bool          isBold;
    lpsm::ArgVec2 linkEmph = ArgVec2(0, 1);
    lpsm::ArgVec2 boldItal = ArgVec2(0, 1);
    for (int i = 0; i < sents; ++i)
    {
        fmtRoll = sent.Roll();
        addLink = static_cast<bool>(linkEmph.Roll());
        isBold  = static_cast<bool>(boldItal.Roll());
        if (i == 0 && useLipsum)
        {
            ret += lpsm::GenerateDefaultLipsumSentence();
        }
        else if ((fmtRoll == sent.min) && addLink)
        {
            ret += lpsm::GenerateMarkdownLink(linkURL,
                                              wordFmt,
                                              fragFmt,
                                              wordLink);
        }
        else if ((fmtRoll == sent.min) && !addLink)
        {
            ret += lpsm::GenerateMarkdownEmphasis(isBold, wordFmt, fragFmt);
        }
        else
        {
            ret += lpsm::GenerateSentence(word, frag);
        }
        ret += " ";
    }
    ret += "\n\n";
    return ret;
}

std::string lpsm::GenerateMarkdownLink(const std::string&   url,
                                       const lpsm::ArgVec2& word,
                                       const lpsm::ArgVec2& frag,
                                       const lpsm::ArgVec2& wordURL)
{
    std::string ret;
    ret += std::string("[") += lpsm::GenerateSentence(word, frag) +=
            std::string("](") += url;
    std::string words = lpsm::GenerateSentenceFragment(wordURL);
    for (char& c : words)
    {
        if (c == ' ')
        {
            c = '-';
        }
    }
    ret += std::string("#") += words += ")";
    return ret;
}

std::string lpsm::GenerateMarkdownEmphasis(bool                 isBold,
                                           const lpsm::ArgVec2& word,
                                           const lpsm::ArgVec2& frag)
{
    std::string ret;
    ret += "*";
    if (isBold)
    {
        ret += "*";
    }
    ret += lpsm::GenerateSentence(word, frag);
    ret += "*";
    if (isBold)
    {
        ret += "*";
    }
    return ret;
}

std::string lpsm::GenerateMarkdownHeader(int level, const lpsm::ArgVec2& word)
{
    std::string ret;
    for (int i = 0; i < level; ++i)
    {
        ret += "#";
    }
    ret += " ";
    std::string words = lpsm::GenerateSentenceFragment(word);
    words.at(0)       = std::toupper(words.at(0));
    ret += words += "\n\n";
    return ret;
}

std::string lpsm::Generator::word(int num)
{
    return lpsm::GenerateWords(num);
}
std::string lpsm::Generator::sentence(int num, bool useLipsum)
{
    return lpsm::GenerateSentences(num,
                                   lpsm::ArgVec2(4, 9),
                                   lpsm::ArgVec2(1, 3),
                                   useLipsum);
}
std::string lpsm::Generator::sentence_fragment()
{
    return lpsm::GenerateSentenceFragment();
}
std::string lpsm::Generator::paragraph(int num, bool useLipsum)
{
    return lpsm::GenerateParagraphs(num,
                                    lpsm::ArgVec2(4, 9),
                                    lpsm::ArgVec2(1, 3),
                                    lpsm::ArgVec2(5, 8),
                                    useLipsum);
}
std::string lpsm::GenerateWords(int wordCount)
{
    std::string ret;
    for (int i = 0; i < wordCount; ++i)
    {
        ret += lpsm::GenerateWord() += " ";
    }
    ret.pop_back();
    return ret;
}

int lpsm::internal::RandomNumber(int min, int max)
{
    static std::random_device       rd;
    std::mt19937                    gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

std::string lpsm::HTMLify(const char* str)
{
    return lpsm::HTMLify(std::string(str));
}

std::string lpsm::GenerateSentencesX(int  sentCount,
                                     int  minWord,
                                     int  maxWord,
                                     int  minFrag,
                                     int  maxFrag,
                                     bool useLipsum)
{
    return lpsm::GenerateSentences(sentCount,
                                   lpsm::ArgVec2(minWord, maxWord),
                                   lpsm::ArgVec2(minFrag, maxFrag),
                                   useLipsum);
}

std::string lpsm::GenerateParagraphsX(int  paraCount,
                                      int  minWord,
                                      int  maxWord,
                                      int  minFrag,
                                      int  maxFrag,
                                      int  minSent,
                                      int  maxSent,
                                      bool useLipsum)
{
    return lpsm::GenerateParagraphs(paraCount,
                                    lpsm::ArgVec2(minWord, maxWord),
                                    lpsm::ArgVec2(minFrag, maxFrag),
                                    lpsm::ArgVec2(minSent, maxSent),
                                    useLipsum);
}

std::string lpsm::GenerateParagraphX(int  minWord,
                                     int  maxWord,
                                     int  minFrag,
                                     int  maxFrag,
                                     int  minSent,
                                     int  maxSent,
                                     bool useLipsum)
{
    return lpsm::GenerateParagraph(lpsm::ArgVec2(minWord, maxWord),
                                   lpsm::ArgVec2(minFrag, maxFrag),
                                   lpsm::ArgVec2(minSent, maxSent),
                                   useLipsum);
}

std::string
lpsm::GenerateSentenceX(int minWord, int maxWord, int minFrag, int maxFrag)
{
    return lpsm::GenerateSentence(lpsm::ArgVec2(minWord, maxWord),
                                  lpsm::ArgVec2(minFrag, maxFrag));
}

std::string lpsm::GenerateSentenceFragmentX(int minWord, int maxWord)
{
    return lpsm::GenerateSentenceFragment(lpsm::ArgVec2(minWord, maxWord));
}

std::string lpsm::internal::HandleHTMLEntity(const std::string& str)
{
    std::string result;
    for (const auto& c : str)
    {
        switch (c)
        {
            case '&':
            {
                result += "&amp;";
                break;
            }
            case '<':
            {
                result += "&lt;";
                break;
            }
            case '>':
            {
                result += "&gt;";
                break;
            }
            case '"':
            {
                result += "&quot;";
                break;
            }
            case '\'':
            {
                result += "&apos;";
                break;
            }
            default:
            {
                result.push_back(c);
            }
        }
    }
    return result;
}

lpsm::ArgVec2::ArgVec2(int min, int max)
{
    this->min = min;
    this->max = max;
}

int lpsm::ArgVec2::Roll() const
{
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(min, max);
    return lpsm::internal::RandomNumber(min, max);
}

std::string lpsm::HTMLify(const std::string& str)
{
    std::stringstream ss(str);
    std::string       line;
    std::string       result;
    while (std::getline(ss, line))
    {
        if (!line.empty())
        {
            result += std::string("<p>") +=
                    lpsm::internal::HandleHTMLEntity(line) +=
                    std::string("</p>\n");
        }
    }
    return result;
}

std::string lpsm::GenerateSentences(int                  sentCount,
                                    const lpsm::ArgVec2& word,
                                    const lpsm::ArgVec2& frag,
                                    bool                 useLipsum)
{
    std::string result;
    if (useLipsum)
    {
        result += lpsm::GenerateDefaultLipsumSentence() += " ";
        for (int i = 0; i < sentCount - 1; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    else
    {
        for (int i = 0; i < sentCount; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    return result;
}

std::string lpsm::GenerateDefaultLipsumSentence()
{
    return "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
}

std::string lpsm::GenerateWord()
{
#    include "lipsum.inl"
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(0, lipsumVec.size() - 1);
    int randomIdx = lpsm::internal::RandomNumber(0, lipsumVec.size() - 1);
    return lipsumVec.at(randomIdx);
}

std::string lpsm::GenerateSentenceFragment(const lpsm::ArgVec2& word)
{
    std::string result;
    int         numWords = word.Roll();
    for (int i = 0; i < numWords; ++i)
    {
        result += lpsm::GenerateWord() += " ";
    }
    result.pop_back(); // remove trailing space
    return result;
}

std::string lpsm::GenerateSentence(const lpsm::ArgVec2& word,
                                   const lpsm::ArgVec2& frag)
{
    constexpr int CHANCE_COMMA = 97;
    constexpr int CHANCE_SEMI  = 9;
    std::string   result;
    int           words = word.Roll();
    int           frags = frag.Roll();
    // static std::random_device rd;
    // static std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dist(0, 100);
    for (int i = 0; i < frags; ++i)
    {
        result += lpsm::GenerateSentenceFragment(word);
        int check = lpsm::internal::RandomNumber(0, 100);
        // don't do if only one fragment
        if (i != frags - 1)
        {
            if (check < CHANCE_SEMI)
            {
                result += "; ";
            }
            else if (check < CHANCE_COMMA)
            {
                result += ", ";
            }
            else
            {
                result += " - ";
            }
        }
    }
    result += ".";
    result.at(0) = std::toupper(result.at(0));
    return result;
}

std::string lpsm::GenerateParagraph(const lpsm::ArgVec2& word,
                                    const lpsm::ArgVec2& frag,
                                    const lpsm::ArgVec2& sent,
                                    bool                 useLipsum)
{
    std::string result = "\t";
    int         sents  = sent.Roll();
    if (!useLipsum)
    {
        for (int i = 0; i < sents; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    else
    {
        result += lipsum::GenerateDefaultLipsumSentence() += " ";
        for (int i = 0; i < sents - 1; ++i)
        {
            result += lpsm::GenerateSentence(word, frag) += " ";
        }
    }
    // remove trailing space
    result.pop_back();
    result += "\n";
    return result;
}

std::string lpsm::GenerateParagraphs(int                  paraCount,
                                     const lpsm::ArgVec2& word,
                                     const lpsm::ArgVec2& frag,
                                     const lpsm::ArgVec2& sent,
                                     bool                 useLipsum)
{
    std::string result;
    if (!useLipsum)
    {

        for (int i = 0; i < paraCount; ++i)
        {
            result += lpsm::GenerateParagraph(word, frag, sent, false);
        }
    }
    else
    {
        result += lpsm::GenerateParagraph(word, frag, sent, true);
        for (int i = 0; i < paraCount - 1; ++i)
        {
            result += lpsm::GenerateParagraph(word, frag, sent, false);
        }
    }
    return result;
}

#endif
