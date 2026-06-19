#include "../include/XORCipher.h"

XORCipher::XORCipher(const std::string& key) 
    : Cipher("XOR Cipher") {
    setKey(key);
}

std::string XORCipher::performXOR(const std::string& data) {
    std::string result = "";
    for (size_t i = 0; i < data.length(); i++) {
        result += (char)(data[i] ^ xor_key[i % xor_key.size()]);
    }
    return result;
}

std::string XORCipher::encrypt(const std::string& plaintext) {
    return performXOR(plaintext);
}

std::string XORCipher::decrypt(const std::string& ciphertext) {
    return performXOR(ciphertext);
}

void XORCipher::setKey(const std::string& newKey) {
    xor_key.clear();
    for (char c : newKey) {
        xor_key.push_back((unsigned char)c);
    }
    key = newKey;
}

std::string XORCipher::generateKey(int length) {
    key = "";
    for (int i = 0; i < length; i++) {
        key += (char)(rand() % 256);
    }
    setKey(key);
    return key;
}

void XORCipher::setXORKey(const std::vector<unsigned char>& k) {
    xor_key = k;
}

std::vector<unsigned char> XORCipher::getXORKey() const {
    return xor_key;
}
