#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class FileEncryptor {
private:
    string filename;
    int encryptionKey;
    char encryptChar(char c){
        if(isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            return (c - base + encryptionKey) % 26 + base;
        }
        return c;
    }
    char decryptChar(char c) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            return (c - base - encryptionKey + 26) % 26 + base;
        }
        return c;
    }

public:
    FileEncryptor(string fname, int key) : filename(fname), encryptionKey(key) {}
    void encryptAndWrite(string message) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file for writing.\n";
            return;
        }
        for (char c : message) {
            file << encryptChar(c);
        }
        file.close();
        cout << "Message successfully encrypted and stored in " << filename << "\n";
    }

    string readAndDecrypt() {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file for reading.\n";
            return "";
        }
        string decryptedMessage = "";
        char c;
        while (file.get(c)) {
            decryptedMessage += decryptChar(c);
        }
        file.close();
        return decryptedMessage;
    }
    void displayFileContents() {
        string message = readAndDecrypt();
        cout << "Decrypted Message: " << message << "\n";
    }
};
int main() {
    FileEncryptor fe("data.txt", 3);

    int choice;
    string message;

    cout << "1. Encrypt and Write Message\n";
    cout << "2. Read and Decrypt Message\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter a message to encrypt: ";
        getline(cin, message);
        fe.encryptAndWrite(message);
    } else if (choice == 2) {
        cout << "\nReading and decrypting file...\n";
        fe.displayFileContents();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
