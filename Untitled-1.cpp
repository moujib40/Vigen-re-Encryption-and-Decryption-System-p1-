#include <iostream>
#include <string>
using namespace std;

char alphabet[26] = {
'A','B','C','D','E','F','G','H','I','J','K','L','M',
'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};

// BASIC MODE
string encryptBasic(string text, string key) {
    string result = "";
    int k = 0;

    for (char c : text) {
        if (isalpha(c)) {
            int p = toupper(c) - 'A';
            int keyVal = toupper(key[k % key.length()]) - 'A';

            char enc = alphabet[(p + keyVal) % 26];
            if (islower(c)) enc = tolower(enc);

            result += enc;
            k++;
        } else {
            result += c;
        }
    }
    return result;
}

string decryptBasic(string text, string key) {
    string result = "";
    int k = 0;

    for (char c : text) {
        if (isalpha(c)) {
            int p = toupper(c) - 'A';
            int keyVal = toupper(key[k % key.length()]) - 'A';

            char dec = alphabet[(p - keyVal + 26) % 26];
            if (islower(c)) dec = tolower(dec);

            result += dec;
            k++;
        } else {
            result += c;
        }
    }
    return result;
}

// ADVANCED MODE (ASCII 32–126)
string encryptAdvanced(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        result += char(((text[i] - 32 + key[i % key.length()] - 32) % 95) + 32);
    }
    return result;
}

string decryptAdvanced(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        result += char(((text[i] - 32 - (key[i % key.length()] - 32) + 95) % 95) + 32);
    }
    return result;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Vigenere Cipher Program ===\n";
        cout << "1 - Basic Mode\n";
        cout << "2 - Advanced Mode\n";
        cout << "3 - Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 3) {
            cout << "Program closed.\n";
            break;
        }

        string text, key;

        cout << "Enter text: ";
        getline(cin, text);

        cout << "Enter key: ";
        getline(cin, key);

        string encrypted, decrypted;

        if (choice == 1) {
            encrypted = encryptBasic(text, key);
            decrypted = decryptBasic(encrypted, key);
        }
        else if (choice == 2) {
            encrypted = encryptAdvanced(text, key);
            decrypted = decryptAdvanced(encrypted, key);
        }
        else {
            cout << "Invalid option.\n";
            continue;
        }

        cout << "\nEncrypted text: " << encrypted << endl;
        cout << "Decrypted text: " << decrypted << endl;
    }

    return 0;
}