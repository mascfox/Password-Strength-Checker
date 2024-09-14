#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if the password contains a special character
bool contains_special_char(const char* password) {
    const char* special_characters = "!@#$%^&*(),.?\":{}|<>";
    for (int i = 0; i < strlen(password); i++) {
        if (strchr(special_characters, password[i])) {
            return true;
        }
    }
    return false;
}

// Function to check if the password is a common password
bool is_common_password(const char* password) {
    const char* common_passwords[] = {"password", "123456", "123456789", "qwerty", "abc123", "password1"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(password, common_passwords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check the strength of the password
void check_password_strength(const char* password) {
    bool length = false, uppercase = false, lowercase = false, digits = false, special_char = false, common_password = false;

    // Check if password is at least 8 characters long
    if (strlen(password) >= 8) {
        length = true;
    }

    // Check for uppercase letters, lowercase letters, and digits
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercase = true;
        }
        if (islower(password[i])) {
            lowercase = true;
        }
        if (isdigit(password[i])) {
            digits = true;
        }
    }

    // Check for special characters
    special_char = contains_special_char(password);

    // Check if the password is a commonly used weak password
    common_password = is_common_password(password);

    // Output the password strength feedback
    if (length && uppercase && lowercase && digits && special_char && !common_password) {
        printf("Strong password!\n");
    } else {
        printf("Your password could be improved by:\n");
        if (!length) {
            printf("- Increasing the length (at least 8 characters)\n");
        }
        if (!uppercase) {
            printf("- Adding at least one uppercase letter\n");
        }
        if (!lowercase) {
            printf("- Adding at least one lowercase letter\n");
        }
        if (!digits) {
            printf("- Adding at least one digit\n");
        }
        if (!special_char) {
            printf("- Adding at least one special character\n");
        }
        if (common_password) {
            printf("- Avoiding common passwords like 'password' or '123456'\n");
        }
    }
}

// Main menu function
void menu() {
    int choice;
    char password[100];

    while (1) {
        printf("\nPassword Strength Checker Menu:\n");
        printf("1. Check password strength\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a password to check its strength: ");
                scanf("%s", password);
                check_password_strength(password);
                break;

            case 2:
                printf("Exiting the program.\n");
                return; // Exit the program

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Main function
int main() {
    menu(); // Run the menu
    return 0;
}