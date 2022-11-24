#include "../include/header.h"

//  FUNCTION DEFINITIONS:

//      --- PRINT_LIST() ---
void print_list(jag_int array[])
{
    printf("\n");
    // Print List
    for (uint64_t i = 0; i < array[0].main_length; i++)
    {
        printf("Row: %li\n", i+1);
        for (uint64_t j = 0; j < array[i].length; j++)
        {
            printf("%li ", array[i].ptr[j]);
        }
        printf("\n\n");
    }
}

//      --- INF_BUFFER() ---
char *inf_buffer(char *prompt)
{
    printf("%s", prompt);

    // Allocate 1st char in string
    char *s = malloc(sizeof(char));
    if (s == NULL) exit(2);

    uint64_t i = 0;

    // Scan command line until '\n'
    while (true)
    {
        // Scan
        if (scanf("%c", &s[i]) == EOF) exit(3);

        // Check for '\n'
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        else {
            // Reallocate new char
            if ((s = realloc(s, sizeof(char)*(i+2))) == NULL) exit(4);
            i++;
        }
    }

    return s;
}
//     --- START_SCREEN() ---
void start_screen(void)
{
    // INTRO
    printf("\n\t\t~~~ CREATE a JAGGED 2D ARRAY ~~~");
    printf("\n\t~~~ (i.e. A list of lists (each list can be any size)) ~~~");
    printf("\n\n ** Type 'quit' anytime to exit program\n");
    printf("\n ** Type 'new row' anytime to move on to next row (i.e. next list within the main list)\n");
}
