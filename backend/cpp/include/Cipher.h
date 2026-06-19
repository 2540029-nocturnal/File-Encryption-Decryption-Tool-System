#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <vector>

class Cipher {
protected:
    std::string key;
    std::string algorithm_name;

public:
    Cipher(const std::string& name = "Cipher");
    virtual ~Cipher() = default;
    virtual std::string encrypt(const std::string& plaintext) = 0;
    virtual std::string decrypt(const std::string& ciphertext) = 0;
    virtual void setKey(const std::string& newKey) = 0;
    std::string getAlgorithmName() const;
    std::string getKey() const;
    virtual std::string generateKey(int length = 16) = 0;
};

#endif
