//C wrapper
#include "lipsum.h"
#include "lipsum.hpp"
const char* lpsm_GenerateSentence(int minWord, int maxWord)
{
    return lipsum::GenerateSentence(minWord, maxWord).c_str();
}
const char* lpsm_GenerateParagraph(int minSent, int maxSent, int minWord, int maxWord, bool useLipsum)
{
    return lipsum::GenerateParagraph(minSent, maxSent, minWord, maxWord, useLipsum).c_str();
}
const char* lpsm_GenerateParagraphs(int paraCount, int minSent, int maxSent, int minWord, int maxWord, bool useLipsum)
{
    return lipsum::GenerateParagraphs(paraCount, minSent, maxSent, minWord, maxWord, useLipsum).c_str();
}
const char* lpsm_GenerateWord(void)
{
    return lipsum::GenerateWord().c_str();
}
const char* lpsm_GenerateDefaultLipsumSentence(void)
{
    return lipsum::GenerateDefaultLipsumSentence().c_str();
}
const char* lpsm_GenerateSentences(int sentCount, int minWord, int maxWord, bool useLipsum)
{
    return lipsum::GenerateSentences(sentCount, minWord, maxWord, useLipsum).c_str();
}
const char* lpsm_HTMLify(const char* str)
{
    return lipsum::HTMLify(std::string(str)).c_str();
}
