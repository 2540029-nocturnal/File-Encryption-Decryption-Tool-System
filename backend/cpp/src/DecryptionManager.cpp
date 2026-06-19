#include "../include/DecryptionManager.h"

DecryptionManager::DecryptionManager() : current_cipher(nullptr) {}

void DecryptionManager::registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
    if (current_cipher == nullptr) {
        current_cipher = cipher;
    }
}

void DecryptionManager::selectCipher(const std::string& name) {
    if (ciphers.find(name) != ciphers.end()) {
        current_cipher = ciphers[name];
    }
}

std::string DecryptionManager::decrypt(const std::string& ciphertext) {
    if (current_cipher != nullptr) {
        return current_cipher->decrypt(ciphertext);
    }
    return "";
}

std::vector<std::string> DecryptionManager::getAvailableCiphers() const {
    std::vector<std::string> available;
    for (const auto& pair : ciphers) {
        available.push_back(pair.first);
    }
    return available;
}

std::string DecryptionManager::getCurrentCipher() const {
    if (current_cipher != nullptr) {
        return current_cipher->getAlgorithmName();
    }
    return "";
}
