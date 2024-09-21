#include <stdio.h>
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
