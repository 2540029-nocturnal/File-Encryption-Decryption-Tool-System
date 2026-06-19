#include "../include/EncryptionManager.h"

EncryptionManager::EncryptionManager() : current_cipher(nullptr) {}

void EncryptionManager::registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
    if (current_cipher == nullptr) {
        current_cipher = cipher;
    }
}

void EncryptionManager::selectCipher(const std::string& name) {
    if (ciphers.find(name) != ciphers.end()) {
        current_cipher = ciphers[name];
    }
}

std::string EncryptionManager::encrypt(const std::string& plaintext) {
    if (current_cipher != nullptr) {
        return current_cipher->encrypt(plaintext);
    }
    return "";
}

std::vector<std::string> EncryptionManager::getAvailableCiphers() const {
    std::vector<std::string> available;
    for (const auto& pair : ciphers) {
        available.push_back(pair.first);
    }
    return available;
}

std::string EncryptionManager::getCurrentCipher() const {
    if (current_cipher != nullptr) {
        return current_cipher->getAlgorithmName();
    }
    return "";
}
