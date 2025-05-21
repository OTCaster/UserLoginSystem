#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "utils.h" // Ensure this is included if get_string_input is used, or remove if not.
// utils.h is included for get_string_input, which is not used in this specific snippet but is in the original file.
// For username_exists, we might need MAX_USERNAME_LENGTH, typically defined in user.h or a config file.
// For now, let's assume a reasonable max length or define it locally if not available globally.
// #include "../include/user.h" // If MAX_USERNAME_LENGTH is defined there.

#define MAX_LINE_LENGTH 256 // Max length for a line in credentials file
#define CREDENTIALS_FILE "data/credentials.txt" // Path to credentials file
// Define MAX_USERNAME_LENGTH if not available from includes.
// This should ideally be consistent with username array sizes elsewhere.
#ifndef MAX_USERNAME_LENGTH
#define MAX_USERNAME_LENGTH 50
#endif

// Function to check if a username already exists
int username_exists(const char *username) {
    FILE *file = fopen(CREDENTIALS_FILE, "r");
    if (file == NULL) {
        perror("Error opening credentials file for username check");
        return 0; // Cannot confirm, assume not exists or handle error appropriately
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char stored_username[MAX_USERNAME_LENGTH];
        // Extract username from "username,hashed_password"
        char *comma = strchr(line, ',');
        if (comma != NULL) {
            int len = comma - line;
            if (len < MAX_USERNAME_LENGTH) {
                strncpy(stored_username, line, len);
                stored_username[len] = '\0';
                if (strcmp(stored_username, username) == 0) {
                    fclose(file);
                    return 1; // Username found
                }
            }
        }
    }

    fclose(file);
    return 0; // Username not found
}

void login_user() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    get_string_input(username, sizeof(username));

    printf("Enter password: ");
    get_string_input(password, sizeof(password));

    if (validate_credentials(username, password)) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password.\n");
    }
}

int store_credentials(const char *username, const char *hashed_password) {
    FILE *fp = fopen("data/credentials.txt", "a");
    if (fp == NULL) {
        perror("Failed to open credentials file");
        return 0;
    }

    fprintf(fp, "%s,%s\n", username, hashed_password);
    fclose(fp);
    return 1;
}

int validate_credentials(const char *username, const char *password) {
    char stored_username[50];
    char stored_hashed_password[65];
    char hashed_input_password[65];

    hash_password(password, hashed_input_password);

    FILE *fp = fopen("data/credentials.txt", "r");
    if (fp == NULL) {
        perror("Failed to open credentials file");
        return 0;
    }

    int valid = 0;
    while (fscanf(fp, "%49[^,],%64s\n", stored_username, stored_hashed_password) != EOF) {
        if (strcmp(username, stored_username) == 0 && strcmp(hashed_input_password, stored_hashed_password) == 0) {
            valid = 1;
            break;
        }
    }

    fclose(fp);
    return valid;
}

void hash_password(const char *password, char *hashed_output) {
    // Simple hash function for illustration
    // In production, use a secure hash function from a library like OpenSSL
    unsigned long hash = 5381;
    int c;
    while ((c = *password++))
        hash = ((hash << 5) + hash) + c;

    snprintf(hashed_output, 65, "%lu", hash); // Use snprintf for safer string formatting
}
