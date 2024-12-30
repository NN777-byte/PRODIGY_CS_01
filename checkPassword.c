#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPassword(const char *password) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (length < 8) {
        return 0; // Password too short
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (ispunct(password[i])) {
            hasSpecial = 1;
        }
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    if (checkPassword(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak. It must be at least 8 characters long and contain an uppercase letter, a lowercase letter, a digit, and a special character.\n");
    }

    return 0;
}
