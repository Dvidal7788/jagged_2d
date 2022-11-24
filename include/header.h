// HEADER FILE FOR jagged_2d
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

typedef struct jag_int
{
    int64_t *ptr;
    uint64_t length;
    uint64_t main_length;
}
jag_int;

void print_list(jag_int array[]);
char *inf_buffer(char *prompt);
void start_screen(void);

#endif /* HEADER_H */