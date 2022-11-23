// JAGGED 2D ARRAY
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct jag_int
{
    int64_t *ptr;
    uint64_t length;
    uint64_t main_length;
}
jag_int;

void print_list(jag_int array[]);

int main(void)
{
    bool new_row = true;
    uint64_t i = 0, j = 0;

    // MAIN ARRAY
    jag_int *array = malloc(sizeof(jag_int));
    if (array == NULL) return 1;
    array[0].main_length = 1;

    while (true)
    {
        // Allocate Row
        array[i].ptr = malloc(sizeof(int64_t));
        if (array[i].ptr == NULL) return 1;

        array[i].length = 0;
        j = 0;

        // Loop to create Row
        while (true)
        {
            // User Input
            int x;
            printf("Row: %li\nEnter number: ", i+1);
            scanf("%i", &x);

            array[i].ptr[j] = x;

            // Length of Current Row
            array[i].length++;
            print_list(array);

            // Keep Going?
            printf("___ Continue with Current List? (1) ___ OR ___ Create New List? (2) ___ OR QUIT (3)\n");
            scanf("%i", &x);
            if (x == 3) {
                // QUIT
                new_row = false;
                break;
            }
            else if (x == 2) {
                break;
            }

            array[i].ptr = realloc(array[i].ptr, sizeof(int64_t)*(j+2));
            if (array[i].ptr == NULL) return 1;
            j++;

        }

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

    // for (int p = 0; p < array[i].length; p++) {
    //     printf("%li, ", array[i].ptr[p]);
    // }
    // printf("\n");

    // --- FREE ---
    for (i = 0; i < array[0].main_length; i++)
    {
        free(array[i].ptr);
        array[i].ptr = NULL;
    }

    free(array);
    array = NULL;

    return 0;
}
//////
void print_list(jag_int array[])
{
    printf("\n");
    // Print List
    for (int i = 0; i < array[0].main_length; i++)
    {
        for (int j = 0; j < array[i].length; j++)
        {
            printf("%li ", array[i].ptr[j]);
        }
        printf("\n\n");
    }
}
