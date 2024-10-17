#include <iostream>
#include <string>
#include <cctype>

bool isValidPassword(const std::string& password) {
    if (password.length() < 6 || password.length() > 16) {
        return false;
    }

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    std::string specialChars = "!@#$%^&*()-+=<>?{}[]|";

    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (specialChars.find(ch) != std::string::npos) hasSpecial = true;
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
}

int main() {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (isValidPassword(password)) {
        std::cout << "Password is valid.\n";
    } else {
        std::cout << "Password is invalid.\n";
    }
    return 0;
}
