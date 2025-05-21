#include <stdio.h>
#include "user.h"
#include "utils.h"
#include "auth.h"

void register_user() {
    char username[50];
    char password[50];

    printf("Enter new username: ");
    get_string_input(username, sizeof(username));

    // Check if username already exists
    if (username_exists(username)) {
        printf("Username already taken. Please choose a different one.\n");
        return;
    }

    printf("Enter new password: ");
    get_string_input(password, sizeof(password));

    // Hash the password
    char hashed_password[65]; // Buffer to store the custom hashed password string
    hash_password(password, hashed_password);

    // Store credentials
    if (store_credentials(username, hashed_password)) {
        printf("Account created successfully!\n");
    } else {
        printf("Failed to create account. Please try again.\n");
    }
}
