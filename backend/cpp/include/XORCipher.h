#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "Cipher.h"
#include <string>
#include <vector>

class XORCipher : public Cipher {
private:
    std::vector<unsigned char> xor_key;
    std::string performXOR(const std::string& data);
    
public:
    XORCipher(const std::string& key = "default_key");
    ~XORCipher() override = default;
    std::string encrypt(const std::string& plaintext) override;
    std::string decrypt(const std::string& ciphertext) override;
    void setKey(const std::string& newKey) override;
    std::string generateKey(int length = 16) override;
    void setXORKey(const std::vector<unsigned char>& key);
    std::vector<unsigned char> getXORKey() const;
};

#endif
