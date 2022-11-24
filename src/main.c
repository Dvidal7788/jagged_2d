#include "../include/header.h"

// JAGGED 2D ARRAY

int main(void)
{
    // Setup
    start_screen();
    char *list_name = inf_buffer("LIST NAME: ");

    bool new_row = true;
    uint64_t i = 0, j = 0;

    // MAIN ARRAY
    jag_int *array = malloc(sizeof(jag_int));
    if (array == NULL) return 1;
    array[0].main_length = 1;

    while (true)
    {
        // Allocate 1st Index in Row
        array[i].ptr = malloc(sizeof(int64_t));
        if (array[i].ptr == NULL) return 1;

        array[i].length = 0;
        j = 0;

        // Loop to create Row
        while (true)
        {
            // Create regular string from format string for fuction input
            char prompt[50];
            sprintf(prompt, "Row: %li\nEnter number: ", i+1);

            // Scan input
            char *s = inf_buffer(prompt);

            // Check
            if (strcasecmp(s, "quit") == 0) {
                // QUIT
                free(s);
                s = NULL;
                new_row = false;
                break;
            }
            else if (strcasecmp(s, "new row") == 0) {
                free(s);
                break;
            }

            // Check if integer
            bool is_int = true;
            for (uint64_t i = 0; i < strlen(s); i++) {
                if (!isdigit(s[i])) {
                    printf("\n** Not an integer **\n");
                    is_int = false;
                    break;
                }
            }

            if (!is_int) {
                free(s);
                continue;
            }

            // Assign value to current index
            array[i].ptr[j] = atoi(s);

            // Length of Current Row
            array[i].length++;
            printf("\n%s:", list_name);
            print_list(array);


            // Allocate one more index in current row
            array[i].ptr = realloc(array[i].ptr, sizeof(int64_t)*(j+2));
            if (array[i].ptr == NULL) return 1;
            free(s);
            j++;

        }

        // Allocate new Row
        if (new_row) {
            // Realloc Main Array
            array = realloc(array, sizeof(jag_int)*(i+2));
            if (array == NULL) return 1;

            array[0].main_length++;

            i++;
        }
        else break;
    }

    // -- PRINT --
    print_list(array);

    // --- FREE ---
    for (i = 0; i < array[0].main_length; i++)
    {
        free(array[i].ptr);
        array[i].ptr = NULL;
    }

    free(array);
    array = NULL;
    free(list_name);
    list_name = NULL;

    return 0;
}