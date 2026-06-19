#ifndef ENCRYPTION_MANAGER_H
#define ENCRYPTION_MANAGER_H

#include "Cipher.h"
#include <string>
#include <map>
#include <memory>

class EncryptionManager {
private:
    std::map<std::string, std::shared_ptr<Cipher>> ciphers;
    std::shared_ptr<Cipher> current_cipher;
    
public:
    EncryptionManager();
    ~EncryptionManager() = default;
    void registerCipher(const std::string& name, std::shared_ptr<Cipher> cipher);
    void selectCipher(const std::string& name);
    std::string encrypt(const std::string& plaintext);
    std::vector<std::string> getAvailableCiphers() const;
    std::string getCurrentCipher() const;
};

#endif
