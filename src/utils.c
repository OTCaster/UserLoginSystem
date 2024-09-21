#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void get_string_input(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    size_t len = strlen(buffer);
    if (buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    else
        while (getchar() != '\n'); // Clear the input buffer
}

int get_int_input() {
    char buffer[20];
    get_string_input(buffer, sizeof(buffer));
    return atoi(buffer);
}
