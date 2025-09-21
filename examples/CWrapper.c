#include "lipsum.h"
#include <stdio.h>

int main(void)
{
    char* generatedParagraph = lpsm_GenerateParagraph(5, 8, 4, 12, true, 0.75f);
    printf("%s", generatedParagraph);
    lpsm_DeleteString(generatedParagraph);
    return 0;
}
