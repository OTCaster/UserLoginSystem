#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "utils.h"

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

    sprintf(hashed_output, "%lu", hash);
}
