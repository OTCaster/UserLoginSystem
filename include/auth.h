#ifndef AUTH_H
#define AUTH_H

void login_user();
int store_credentials(const char *username, const char *hashed_password);
int validate_credentials(const char *username, const char *password);
void hash_password(const char *password, char *hashed_output);

#endif // AUTH_H
