#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION
#endif

#include <chrono>
#include <functional>
#include <iomanip>
#include <lipsum.hpp>
#include <numeric>
#include <unordered_map>

#define TEST_MAP(name) {#name, Test_##name}
#define BENCHMARK(func, multiplier)                                            \
    std::vector<int> millis;                                                   \
    std::string      content;                                                  \
    millis.reserve(NUM_BENCHMARKS);                                            \
    int newBenchmarkNum =                                                      \
            static_cast<int>(static_cast<float>(BENCHMARK_NUM) * multiplier);  \
    for (int i = 0; i < NUM_BENCHMARKS; ++i)                                   \
    {                                                                          \
        auto start = std::chrono::steady_clock::now();                         \
                                                                               \
        content = gen.func(newBenchmarkNum);                                   \
        (void)content;                                                         \
                                                                               \
        auto end   = std::chrono::steady_clock::now();                         \
        auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(    \
                end - start);                                                  \
        std::cout << milli.count() << '\n';                                    \
        millis.push_back(milli.count());                                       \
    }                                                                          \
                                                                               \
    int   totalMilli = std::accumulate(millis.begin(), millis.end(), 0);       \
    float avgMilli   = static_cast<float>(totalMilli) / NUM_BENCHMARKS;        \
    float perSec = static_cast<float>(newBenchmarkNum) / (avgMilli / 1000.0f); \
                                                                               \
    std::cout << avgMilli << " ms\n";                                          \
    std::cout << perSec << "/s\n"

constexpr int MIN_WORD       = 4;
constexpr int MAX_WORD       = 9;
constexpr int MIN_FRAG       = 1;
constexpr int MAX_FRAG       = 3;
constexpr int MIN_SENT       = 5;
constexpr int MAX_SENT       = 8;
constexpr int MIN_PARA       = 1;
constexpr int MAX_PARA       = 4;
constexpr int NUM_BENCHMARKS = 70;
constexpr int BENCHMARK_NUM  = 1'000'000;

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

static void Test_count_fragments(lpsm::Generator& gen)
{
    int numFrags = lpsm::CountSentenceFragments(
            "This is a test, and this is a test; testing - test, "
            "test, test. "
            "Lorem ipsum, dolor sit, amet.\n\n"
            "- This is a list, first letter not be counted.\n"
            "- Foo bar; baz - qux. (This, is not counted.)");
    if (numFrags != 14)
    {
        LogTestFailure("count_fragments");
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

static void Test_fragment_count_in_bounds(lpsm::Generator& gen)
{
    std::string checking = gen.sentence(1, false);
    int         numFrags = lpsm::CountSentenceFragments(checking);
    std::cout << numFrags << " ( " << MIN_FRAG << ", " << MAX_FRAG << ")\n";
    std::cout << checking << '\n';
    if (numFrags < MIN_FRAG || numFrags > MAX_FRAG)
    {
        LogTestFailure("fragment_count_in_bounds");
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

static void Test_paragraph_count_in_bounds(lpsm::Generator& gen)
{
    std::string checking = gen.text();
    int         numParas = lpsm::CountParagraphs(checking);
    if (numParas < MIN_PARA || numParas > MAX_PARA)
    {
        LogTestFailure("paragraph_count_in_bounds");
    }
}

static void Test_paragraph_count_equal(lpsm::Generator& gen)
{
    std::string checking = gen.paragraph(20);
    int         numParas = lpsm::CountParagraphs(checking);
    if (numParas != 20)
    {
        LogTestFailure("paragraph_count_equal");
    }
}

static void Test_md_sentence_count_in_bounds(lpsm::Generator& gen)
{
    std::string checking = gen.fmt_paragraph(1, lpsm::MARKDOWN);
    int         numSents = lpsm::CountSentences(checking);
    if (numSents < MIN_SENT || numSents > MAX_SENT)
    {
        LogTestFailure("md_sentence_count_in_bounds");
    }
}

static void Test_md_paragraph_count_equal(lpsm::Generator& gen)
{
    std::string checking = gen.fmt_paragraph(50, lpsm::MARKDOWN);
    int         numParas =
            lpsm::CountParagraphs(checking, lpsm::CountParaMethod::Markdown);
    if (numParas != 50)
    {
        LogTestFailure("md_paragraph_count_equal");
    }
}

static void Test_md_text_count_equal(lpsm::Generator& gen)
{
    std::string checking = gen.fmt_text(100, lpsm::MARKDOWN);
    int         numElems =
            lpsm::CountParagraphs(checking, lpsm::CountParaMethod::Markdown);
    if (numElems != 100)
    {
        LogTestFailure("md_text_count_equal");
    }
}

static void Test_benchmark_words(lpsm::Generator& gen)
{
    BENCHMARK(word, 5.0f);
}

static void Test_benchmark_sentences(lpsm::Generator& gen)
{
    BENCHMARK(sentence, 0.5f);
}

static void Test_benchmark_paragraphs(lpsm::Generator& gen)
{
    BENCHMARK(paragraph, 0.0625f);
}

static void Test_benchmark_md_paragraphs(lpsm::Generator& gen)
{
    BENCHMARK(fmt_paragraph, 0.0625f);
}

static void Test_benchmark_md_text(lpsm::Generator& gen)
{
    BENCHMARK(fmt_text, 0.25f);
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Not enough args\n";
        return -1;
    }
    std::cout << std::setprecision(15);
    lpsm::Generator gen;
    std::unordered_map<std::string, std::function<void(lpsm::Generator&)>>
            // clang-format off
    funcMap
    {
        TEST_MAP(count_words),
        TEST_MAP(count_fragments),
        TEST_MAP(count_sentences),
        TEST_MAP(word_count_in_bounds),
        TEST_MAP(word_count_equal),
        TEST_MAP(fragment_count_in_bounds),
        TEST_MAP(sentence_count_in_bounds),
        TEST_MAP(sentence_count_equal),
        TEST_MAP(paragraph_count_in_bounds),
        TEST_MAP(paragraph_count_equal),
        TEST_MAP(md_sentence_count_in_bounds),
        TEST_MAP(md_paragraph_count_equal),
        TEST_MAP(md_text_count_equal),
        TEST_MAP(benchmark_words),
        TEST_MAP(benchmark_sentences),
        TEST_MAP(benchmark_paragraphs),
        TEST_MAP(benchmark_md_paragraphs),
        TEST_MAP(benchmark_md_text)
    };
    // clang-format on

    // largely arbitrary settings
    gen.change_setting("word", MIN_WORD, MAX_WORD);
    gen.change_setting("frag", MIN_FRAG, MAX_FRAG);
    gen.change_setting("sent", MIN_SENT, MAX_SENT);
    gen.change_setting("para", MIN_PARA, MAX_PARA);

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
