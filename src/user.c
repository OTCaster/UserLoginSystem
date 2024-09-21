#include <stdio.h>
#include "user.h"
#include "utils.h"
#include "auth.h"

void register_user() {
    char username[50];
    char password[50];

    printf("Enter new username: ");
    get_string_input(username, sizeof(username));

    printf("Enter new password: ");
    get_string_input(password, sizeof(password));

    // Hash the password
    char hashed_password[65]; // Assuming SHA-256 hash
    hash_password(password, hashed_password);

    // Store credentials
    if (store_credentials(username, hashed_password)) {
        printf("Account created successfully!\n");
    } else {
        printf("Failed to create account. Please try again.\n");
    }
}
