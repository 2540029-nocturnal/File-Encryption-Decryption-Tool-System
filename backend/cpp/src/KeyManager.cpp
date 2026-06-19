#include "../include/KeyManager.h"
#include <algorithm>
#include <random>
#include <sstream>
#include <iomanip>

KeyManager::KeyManager() : key_counter(0) {}

std::string KeyManager::generateRandomString(int length) {
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string result;
    for (int i = 0; i < length; i++) {
        result += charset[rand() % (sizeof(charset) - 1)];
    }
    return result;
}

KeyData KeyManager::generateKey(const std::string& algorithm, const std::string& description) {
    KeyData new_key;
    new_key.key_id = "KEY_" + std::to_string(++key_counter);
    new_key.key_value = generateRandomString(32);
    new_key.algorithm = algorithm;
    new_key.created_date = std::time(nullptr);
    new_key.description = description.empty() ? "Auto-generated key" : description;
    
    keys.push_back(new_key);
    return new_key;
}

KeyData KeyManager::getKey(const std::string& key_id) const {
    for (const auto& k : keys) {
        if (k.key_id == key_id) {
            return k;
        }
    }
    return KeyData{"", "", "", 0, ""};
}

std::vector<KeyData> KeyManager::getAllKeys() const {
    return keys;
}

bool KeyManager::deleteKey(const std::string& key_id) {
    auto it = std::find_if(keys.begin(), keys.end(),
                          [&key_id](const KeyData& k) { return k.key_id == key_id; });
    if (it != keys.end()) {
        keys.erase(it);
        return true;
    }
    return false;
}

bool KeyManager::updateKey(const std::string& key_id, const std::string& new_description) {
    for (auto& k : keys) {
        if (k.key_id == key_id) {
            k.description = new_description;
            return true;
        }
    }
    return false;
}

bool KeyManager::keyExists(const std::string& key_id) const {
    for (const auto& k : keys) {
        if (k.key_id == key_id) {
            return true;
        }
    }
    return false;
}

int KeyManager::getKeyCount() const {
    return keys.size();
}
