#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H

#include <string>
#include <vector>
#include <ctime>

struct KeyData {
    std::string key_id;
    std::string key_value;
    std::string algorithm;
    std::time_t created_date;
    std::string description;
};

class KeyManager {
private:
    std::vector<KeyData> keys;
    int key_counter;
    std::string generateRandomString(int length);
    
public:
    KeyManager();
    ~KeyManager() = default;
    KeyData generateKey(const std::string& algorithm, const std::string& description = "");
    KeyData getKey(const std::string& key_id) const;
    std::vector<KeyData> getAllKeys() const;
    bool deleteKey(const std::string& key_id);
    bool updateKey(const std::string& key_id, const std::string& new_description);
    bool keyExists(const std::string& key_id) const;
    int getKeyCount() const;
};

#endif
