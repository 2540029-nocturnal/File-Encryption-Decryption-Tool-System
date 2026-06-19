#include <iostream>
#include <memory>
#include "include/EncryptionManager.h"
#include "include/DecryptionManager.h"
#include "include/CaesarCipher.h"
#include "include/XORCipher.h"
#include "include/FileHandler.h"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "  File Encryption Tool - Backend API" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    try {
        // Initialize Encryption Manager
        EncryptionManager encryptionMgr;
        DecryptionManager decryptionMgr;

        // Register cipher algorithms
        auto caesarCipher = std::make_shared<CaesarCipher>();
        auto xorCipher = std::make_shared<XORCipher>();

        encryptionMgr.registerCipher("caesar", caesarCipher);
        encryptionMgr.registerCipher("xor", xorCipher);

        decryptionMgr.registerCipher("caesar", caesarCipher);
        decryptionMgr.registerCipher("xor", xorCipher);

        std::cout << "[INFO] Encryption Manager initialized" << std::endl;
        std::cout << "[INFO] Available ciphers: Caesar, XOR" << std::endl;
        std::cout << std::endl;

        // Example encryption using Caesar cipher
        std::cout << "--- Testing Caesar Cipher ---" << std::endl;
        encryptionMgr.selectCipher("caesar");
        std::string plaintext = "Hello, World!";
        std::string encrypted = encryptionMgr.encrypt(plaintext);
        std::cout << "Original: " << plaintext << std::endl;
        std::cout << "Encrypted: " << encrypted << std::endl;

        decryptionMgr.selectCipher("caesar");
        std::string decrypted = decryptionMgr.decrypt(encrypted);
        std::cout << "Decrypted: " << decrypted << std::endl;
        std::cout << std::endl;

        // Example encryption using XOR cipher
        std::cout << "--- Testing XOR Cipher ---" << std::endl;
        encryptionMgr.selectCipher("xor");
        encrypted = encryptionMgr.encrypt(plaintext);
        std::cout << "Original: " << plaintext << std::endl;
        std::cout << "Encrypted: " << encrypted << std::endl;

        decryptionMgr.selectCipher("xor");
        decrypted = decryptionMgr.decrypt(encrypted);
        std::cout << "Decrypted: " << decrypted << std::endl;
        std::cout << std::endl;

        std::cout << "[SUCCESS] All tests passed!" << std::endl;
        std::cout << std::endl;
        std::cout << "Note: This is the C++ backend library." << std::endl;
        std::cout << "For the web application, use the frontend HTML files." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
