#include <stdio.h>

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

    // generate markdown document with 15 "elements"
    char* generatedMarkdown = lpsm_gen_md_text(15);

    printf("%s\n", generatedWords);
    printf("%s", generatedParagraph);
    printf("%s", generatedMarkdown);
    lpsm_DeleteString(generatedParagraph);
    lpsm_DeleteString(generatedWords);
    lpsm_DeleteString(generatedMarkdown);
    return 0;
}
