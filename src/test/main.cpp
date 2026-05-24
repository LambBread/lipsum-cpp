#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif

#include <functional>
#include <lipsum.hpp>
#include <unordered_map>

#define TEST_MAP(name) {#name, Test_##name}

constexpr int MIN_WORD = 7;
constexpr int MAX_WORD = 16;
constexpr int MIN_FRAG = 3;
constexpr int MAX_FRAG = 6;
constexpr int MIN_SENT = 9;
constexpr int MAX_SENT = 15;

static void LogTestFailure(const std::string& test)
{
    std::cerr << "Test " << test << " failed\n";
    std::abort();
}

static void Test_count_words(lpsm::Generator& gen)
{
    int numWords = lpsm::CountWords("Foo bar baz qux quux corge grault garply "
                                    "waldo fred plugh xyzzy thud.");
    if (numWords != 13)
    {
        LogTestFailure("count_words");
    }
}

static void Test_count_sentences(lpsm::Generator& gen)
{
    int numSents = lpsm::CountSentences(
            "This is a sentence. This is another sentence. "
            "[This is a third sentence.](https://this-is-not-a-sentence.com) "
            "(This is not a sentence.)");
    if (numSents != 3)
    {
        LogTestFailure("count_sentences");
    }
}

static void Test_word_count_in_bounds(lpsm::Generator& gen)
{
    std::string checking = gen.fragment();
    int         numWords = lpsm::CountWords(checking);
    if (numWords < MIN_WORD || numWords > MAX_WORD)
    {
        LogTestFailure("word_count_in_bounds");
    }
}

static void Test_word_count_equal(lpsm::Generator& gen)
{
    std::string checking = gen.word(20);
    int         numWords = lpsm::CountWords(checking);
    if (numWords != 20)
    {
        LogTestFailure("word_count_equal");
    }
}

static void Test_sentence_count_in_bounds(lpsm::Generator& gen)
{
    std::string checking = gen.paragraph(1);
    int         numSents = lpsm::CountSentences(checking);
    if (numSents < MIN_SENT || numSents > MAX_SENT)
    {
        LogTestFailure("sentence_count_in_bounds");
    }
}

static void Test_sentence_count_equal(lpsm::Generator& gen)
{
    std::string checking = gen.sentence(20);
    int         numSents = lpsm::CountSentences(checking);
    if (numSents != 20)
    {
        LogTestFailure("sentence_count_equal");
    }
}

static void Test_md_sentence_count_in_bounds(lpsm::Generator& gen)
{
    std::string checking = gen.md_paragraph(1);
    int         numSents = lpsm::CountSentences(checking);
    if (numSents < MIN_SENT || numSents > MAX_SENT)
    {
        LogTestFailure("md_sentence_count_in_bounds");
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Not enough args\n";
        return -1;
    }
    lpsm::Generator gen;
    std::unordered_map<std::string, std::function<void(lpsm::Generator&)>>
            funcMap{TEST_MAP(count_words),
                    TEST_MAP(count_sentences),
                    TEST_MAP(word_count_in_bounds),
                    TEST_MAP(word_count_equal),
                    TEST_MAP(sentence_count_in_bounds),
                    TEST_MAP(sentence_count_equal),
                    TEST_MAP(md_sentence_count_in_bounds)};

    // largely arbitrary settings
    gen.change_setting("word", MIN_WORD, MAX_WORD);
    gen.change_setting("frag", MIN_FRAG, MAX_FRAG);
    gen.change_setting("sent", MIN_SENT, MAX_SENT);

    auto funcToCall = funcMap[std::string(argv[1])];
    if (funcToCall)
    {
        funcMap[std::string(argv[1])](gen);
    }
    else
    {
        std::cerr << "Unknown test\n";
        return -1;
    }

    return 0;
}
