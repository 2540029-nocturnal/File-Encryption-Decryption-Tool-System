#ifndef DECRYPTION_MANAGER_H
#define DECRYPTION_MANAGER_H

#include "Cipher.h"
#include <string>
#include <map>
#include <memory>

class DecryptionManager {
private:
    std::map<std::string, std::shared_ptr<Cipher>> ciphers;
    std::shared_ptr<Cipher> current_cipher;
    
public:
    DecryptionManager();
    ~DecryptionManager() = default;
    void registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher);
    void selectCipher(const std::string& name);
    std::string decrypt(const std::string& ciphertext);
    std::vector<std::string> getAvailableCiphers() const;
    std::string getCurrentCipher() const;
};

#endif
