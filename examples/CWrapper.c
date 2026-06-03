#include <lipsum.h>

int main(void)
{
    lpsm_GeneratorHandle gen = lpsm_Generator("dog", 0);

    // Change setting to 6-9 words per sentence fragment.
    lpsm_Generator_change_setting(gen, "word", 6, 9);

    // Generate 5 words.
    char* generatedWords = lpsm_Generator_word(gen, 5);

    // Generate a Markdown document with 15 elements.
    char* generatedMarkdown = lpsm_Generator_md_text(gen, 15, LPSM_MARKDOWN);

    printf("%s\n", generatedWords);
    printf("%s", generatedMarkdown);

    lpsm_GeneratorDestroy(gen);
    lpsm_DeleteString(generatedWords);
    lpsm_DeleteString(generatedMarkdown);
    return 0;
}
