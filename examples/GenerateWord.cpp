#define LIPSUM_IMPLEMENTATION //not necessary for static library builds
#include "lipsum.hpp"
int main()
{
    //generate a random word
    std::cout << lipsum::GenerateWord() << '\n';
    return 0;
}
