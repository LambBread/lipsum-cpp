#include "lipsum.h"

int main(void)
{
    // Generate 5 words.
    char* generatedWords = lpsm_gen_word(5);
    // generate a paragraph with 4-9 words per sentence fragment,
    // 1-3 sentence fragments per sentence,
    // 5-8 sentences per paragraph,
    // start with "Lorem ipsum..."
    char* generatedParagraph = lpsm_GenerateParagraph(4, 9, 1, 3, 5, 8, true);

    // generate markdown document with 15 elements
    char* generatedMarkdown = lpsm_gen_md_text(15);

    // create a lpsm::ArgVec2
    lpsm_ArgVec2Handle handle = lpsm_ArgVec2(4, 10);

    // generate a sentence fragment with 4-10 words
    char* example = lpsm_GenerateSentenceFragmentS(handle, false);

    // temp object, will be deleted in paragraph generation
    lpsm_ArgVec2Handle wordAv2 = lpsm_ArgVec2(4, 9);

    // equivalent to first paragraph generation
    char* paragraphWithS = lpsm_GenerateParagraphS(wordAv2,
                                                   lpsm_ArgVec2(1, 3),
                                                   lpsm_ArgVec2(5, 8),
                                                   true,
                                                   true);

    // roll
    printf("%d\n", lpsm_ArgVec2Roll(handle));

    printf("%s\n", example);
    printf("%s\n", generatedWords);
    printf("%s", generatedParagraph);
    printf("%s", generatedMarkdown);
    printf("%s", paragraphWithS);

    // delete stuff
    lpsm_ArgVec2Destroy(handle);
    lpsm_DeleteString(generatedParagraph);
    lpsm_DeleteString(generatedWords);
    lpsm_DeleteString(generatedMarkdown);
    lpsm_DeleteString(paragraphWithS);

    // undefined behaviour
    // causes segfault
    // printf("%d\n", lpsm_ArgVec2Roll(wordAv2));
    return 0;
}
