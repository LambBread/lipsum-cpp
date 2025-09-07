//only for single-header usage
#define LIPSUM_IMPLEMENTATION
#include "lipsum.hpp"

int main()
{
    //generates 6 sentences each with 4-12 words, starting with "Lorem ipsum..." (default)
    std::cout << lipsum::GenerateSentences() << '\n';
    //generates 4 sentences each with 8-20 words, not starting with "Lorem ipsum..."
    std::cout << lipsum::GenerateSentences(4, 8, 20, false) << '\n';
    return 0;
}
