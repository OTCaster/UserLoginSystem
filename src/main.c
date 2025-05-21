#include <stdio.h>
#include <limits.h> // Required for INT_MIN
#include "user.h"
#include "auth.h"
#include "utils.h"

int main() {
    int choice;
    do {
        printf("=== User Login System ===\n");
        printf("1. Create Account\n");
        printf("2. Log In\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        choice = get_int_input(); // A utility function to safely get integer input

        if (choice == INT_MIN) {
            // Error messages are printed by get_int_input to stderr.
            // We can add a generic message here or rely on those.
            // printf("Invalid input. Please enter a valid integer option.\n");
            // The error messages from get_int_input are usually sufficient.
            // We just need to re-prompt.
            continue; // Skip the rest of the loop and re-prompt
        }

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
