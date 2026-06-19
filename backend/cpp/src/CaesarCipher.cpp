#include "../include/CaesarCipher.h"
#include <cctype>

CaesarCipher::CaesarCipher(int shift) 
    : Cipher("Caesar Cipher"), shift_value(shift % 26) {}

char CaesarCipher::shiftChar(char c, int shift) {
    if (std::isalpha(c)) {
        if (std::isupper(c)) {
            return ((c - 'A' + shift) % 26) + 'A';
        } else {
            return ((c - 'a' + shift) % 26) + 'a';
        }
    }
    return c;
}

std::string CaesarCipher::encrypt(const std::string& plaintext) {
    std::string ciphertext = "";
    for (char c : plaintext) {
        ciphertext += shiftChar(c, shift_value);
    }
    return ciphertext;
}

std::string CaesarCipher::decrypt(const std::string& ciphertext) {
    std::string plaintext = "";
    for (char c : ciphertext) {
        plaintext += shiftChar(c, -shift_value);
    }
    return plaintext;
}

void CaesarCipher::setKey(const std::string& newKey) {
    try {
        shift_value = std::stoi(newKey) % 26;
        key = newKey;
    } catch (...) {
        shift_value = 3;
        key = "3";
    }
}

std::string CaesarCipher::generateKey(int length) {
    int random_shift = rand() % 26;
    key = std::to_string(random_shift);
    shift_value = random_shift;
    return key;
}

void CaesarCipher::setShift(int shift) {
    shift_value = shift % 26;
    key = std::to_string(shift_value);
}

int CaesarCipher::getShift() const {
    return shift_value;
}
