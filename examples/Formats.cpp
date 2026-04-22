#ifndef LIPSUM_BUILD_STATIC
#    define LIPSUM_IMPLEMENTATION // only for header-only usage
#endif
#include "lipsum.hpp"

int main()
{
    // generate with 30 choices, with sentences of 1-3 sentence fragments of 4-9
    // words (default)
    std::cout << lpsm::GenerateXMLDocument() << '\n';

    // generate with 40 choices, with sentences of 3-6 sentence fragments of
    // 7-10 words
    std::cout << lpsm::GenerateXMLDocument(40,
                                           lpsm::ArgVec2(7, 10),
                                           lpsm::ArgVec2(3, 6))
              << "\n\n";

    // generate at recursion depth 0, with maximum depth 3, with 2-5 items
    // (default)
    std::cout << lpsm::GenerateJSONObject() << '\n';

    // generate at recursion depth 0, with maximum depth 5, with 6-9 items
    // (default)
    std::cout << lpsm::GenerateJSONObject(0, 5, lpsm::ArgVec2(6, 9)) << "\n\n";

    // generate at recursion depth 0, with maximum depth 3, with 2-5 items
    // (default)
    std::cout << lpsm::GenerateJSONArray() << '\n';

    // generate at recursion depth 0, with maximum depth 5, with 6-9 items
    std::cout << lpsm::GenerateJSONArray(0, 5, lpsm::ArgVec2(6, 9)) << "\n\n";

    // generate at recursion depth 0, with maximum depth 3, with 2-5 items
    // (default)
    std::cout << lpsm::GenerateJSONValue() << '\n';

    // generate at recursion depth 0, with maximum depth 5, with 6-9 items
    std::cout << lpsm::GenerateJSONValue(0, 5, lpsm::ArgVec2(6, 9)) << "\n\n";

    // generate random number
    std::cout << lpsm::GenerateJSONNumber() << '\n';

    // generate random string
    std::cout << lpsm::GenerateJSONString() << "\n\n\n\n";

    // equivalents with "X" functions

    std::cout << lpsm::GenerateXMLDocumentX(40, 7, 10, 3, 6) << "\n\n";
    std::cout << lpsm::GenerateJSONObjectX(0, 5, 6, 9) << "\n\n";
    std::cout << lpsm::GenerateJSONArrayX(0, 5, 6, 9) << "\n\n";
    std::cout << lpsm::GenerateJSONValueX(0, 5, 6, 9) << "\n\n";

    return 0;
}
