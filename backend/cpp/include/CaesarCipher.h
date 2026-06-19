#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "Cipher.h"
#include <string>

class CaesarCipher : public Cipher {
private:
    int shift_value;
    char shiftChar(char c, int shift);
    
public:
    CaesarCipher(int shift = 3);
    ~CaesarCipher() override = default;
    std::string encrypt(const std::string& plaintext) override;
    std::string decrypt(const std::string& ciphertext) override;
    void setKey(const std::string& newKey) override;
    std::string generateKey(int length = 16) override;
    void setShift(int shift);
    int getShift() const;
};

#endif
