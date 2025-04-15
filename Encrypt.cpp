#include <iostream>
#include <fstream>
#include <string>

class FileEncryptor {
private:
    std::string filename;
    int encryptionKey;

    // Caesar Cipher Encryption
    char encryptChar(char c) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            return (c - base + encryptionKey) % 26 + base;
        }
        return c;
    }

    // Caesar Cipher Decryption
    char decryptChar(char c) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            return (c - base - encryptionKey + 26) % 26 + base;
        }
        return c;
    }

public:
    // Constructor
    FileEncryptor(std::string fname, int key) : filename(fname), encryptionKey(key) {}

    // Encrypt and write message to file
    void encryptAndWrite(std::string message) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }
        for (char c : message) {
            file << encryptChar(c);
        }
        file.close();
        std::cout << "Message successfully encrypted and stored in " << filename << "\n";
    }

    // Read and decrypt message from file
    std::string readAndDecrypt() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file for reading.\n";
            return "";
        }
        std::string decryptedMessage = "";
        char c;
        while (file.get(c)) {
            decryptedMessage += decryptChar(c);
        }
        file.close();
        return decryptedMessage;
    }

    // Display decrypted file contents
    void displayFileContents() {
        std::string message = readAndDecrypt();
        std::cout << "Decrypted Message: " << message << "\n";
    }
};

// Main function to demonstrate functionality
int main() {
    FileEncryptor fe("data.txt", 3);

    int choice;
    std::string message;

    std::cout << "1. Encrypt and Write Message\n";
    std::cout << "2. Read and Decrypt Message\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // To ignore newline character after integer input

    if (choice == 1) {
        std::cout << "Enter a message to encrypt: ";
        std::getline(std::cin, message);
        fe.encryptAndWrite(message);
    } else if (choice == 2) {
        std::cout << "\nReading and decrypting file...\n";
        fe.displayFileContents();
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
