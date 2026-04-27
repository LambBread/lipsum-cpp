#include "lipsum.h"

int main(void)
{
    lpsm_SourceHandle    source = lpsm_Source("default");
    lpsm_GeneratorHandle gen    = lpsm_Generator("dog");

    // change to 6-9 words per sentence fragment
    lpsm_Generator_change_setting(gen, "word", 6, 9);

    // Generate 5 words.
    char* generatedWords = lpsm_Generator_word(gen, 5);

    // generate a paragraph with 4-9 words per sentence fragment,
    // 1-3 sentence fragments per sentence,
    // 5-8 sentences per paragraph,
    // start with "Lorem ipsum..."
    char* generatedParagraph =
            lpsm_GenerateParagraph(4, 9, 1, 3, 5, 8, true, source);

    // generate markdown document with 15 elements
    char* generatedMarkdown = lpsm_Generator_md_text(gen, 15);

    // create a lpsm::ArgVec2
    lpsm_ArgVec2Handle handle = lpsm_ArgVec2(4, 10);

    // generate a sentence fragment with 4-10 words
    char* example = lpsm_GenerateSentenceFragmentS(handle, source, false);

    // temp object, will be deleted in paragraph generation
    lpsm_ArgVec2Handle wordAv2 = lpsm_ArgVec2(4, 9);

    // equivalent to first paragraph generation
    char* paragraphWithS = lpsm_GenerateParagraphS(wordAv2,
                                                   lpsm_ArgVec2(1, 3),
                                                   lpsm_ArgVec2(5, 8),
                                                   true,
                                                   source,
                                                   true);

    // roll
    printf("%d\n", lpsm_ArgVec2_roll(handle));

    printf("%s\n", example);
    printf("%s\n", generatedWords);
    printf("%s", generatedParagraph);
    printf("%s", generatedMarkdown);
    printf("%s", paragraphWithS);

    // delete objects
    lpsm_ArgVec2Destroy(handle);
    lpsm_SourceDestroy(source);
    lpsm_GeneratorDestroy(gen);

    lpsm_DeleteString(generatedParagraph);
    lpsm_DeleteString(generatedWords);
    lpsm_DeleteString(generatedMarkdown);
    lpsm_DeleteString(paragraphWithS);

    // undefined behaviour
    // causes segfault
    // printf("%d\n", lpsm_ArgVec2_roll(wordAv2));
    return 0;
}
