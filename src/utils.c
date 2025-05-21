#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strlen if used by get_string_input indirectly
#include <limits.h> // For INT_MIN, INT_MAX
#include <errno.h>  // For errno and ERANGE
#include <ctype.h>  // For isspace
#include "utils.h" // Assuming get_string_input is here

void get_string_input(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') { // Check len > 0 before accessing buffer[len-1]
        buffer[len - 1] = '\0';
    } else if (len == size -1 && buffer[len-1] != '\n') { // Input was too long and truncated
        // Clear the rest of the input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    // If input is shorter than buffer and no newline, it means EOF or error,
    // but get_string_input doesn't explicitly handle that beyond what fgets does.
}

int get_int_input() {
    char buffer[20]; // Buffer for string input
    char *endptr;
    long val;

    get_string_input(buffer, sizeof(buffer));

    // Strip leading/trailing whitespace from buffer before strtol, as strtol only skips leading.
    // This is optional but can make input more robust. For now, we'll rely on strtol's behavior.
    // A simple way to remove trailing whitespace:
    // for (int i = strlen(buffer) - 1; i >= 0 && isspace((unsigned char)buffer[i]); i--) buffer[i] = '\0';
    // And leading:
    // char *trimmed_buffer = buffer;
    // while (isspace((unsigned char)*trimmed_buffer)) trimmed_buffer++;
    // Then use trimmed_buffer with strtol.
    // For simplicity, let's proceed without manual trimming first.

    errno = 0; // Reset errno before call to strtol
    val = strtol(buffer, &endptr, 10); // Base 10 conversion

    // Check for various errors

    // 1. No digits were found at all. endptr would be equal to buffer.
    if (endptr == buffer) {
        fprintf(stderr, "Invalid input: No digits were found.\n");
        return INT_MIN; // Error indicator
    }

    // 2. Additional characters after the number. *endptr should be '\0'.
    //    We should also allow for trailing whitespace to be ignored.
    char *temp_ptr = endptr;
    while (*temp_ptr != '\0' && isspace((unsigned char)*temp_ptr)) {
        temp_ptr++;
    }
    if (*temp_ptr != '\0') {
        fprintf(stderr, "Invalid input: Extra characters after number ('%s').\n", temp_ptr);
        return INT_MIN; // Error indicator
    }

    // 3. Number out of range.
    //    Check errno for ERANGE, and also explicitly check if val is outside int bounds
    //    because strtol might successfully parse a number that's too large/small for an int
    //    but fits in a long, without setting ERANGE if it fits in `long`.
    if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || (val > INT_MAX || val < INT_MIN)) {
        fprintf(stderr, "Invalid input: Number out of range for an int.\n");
        return INT_MIN; // Error indicator
    }

    return (int)val;
}
