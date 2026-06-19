#include "../include/Cipher.h"
#include <iostream>

Cipher::Cipher(const std::string& name) : algorithm_name(name), key("") {}

std::string Cipher::getAlgorithmName() const {
    return algorithm_name;
}

std::string Cipher::getKey() const {
    return key;
}
