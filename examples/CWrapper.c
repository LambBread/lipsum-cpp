#include "lipsum.h"
#include <stdio.h>

int main(void)
{
    char* generatedParagraph = lpsm_GenerateParagraph(5, 8, 4, 12, true, 0.75f);
    char* htmlified = lpsm_HTMLify("This is a paragraph\n\n&& And this is <<another paragraph.>>\n");
    printf("%s", generatedParagraph);
    printf("%s", htmlified);
    lpsm_DeleteString(generatedParagraph);
    lpsm_DeleteString(htmlified);
    return 0;
}
