#ifndef USER_H
#define USER_H

#include <string>
#include <ctime>

class User {
private:
    std::string user_id;
    std::string username;
    std::string email;
    std::string password_hash;
    std::time_t created_date;
    std::time_t last_login;
    bool is_active;
    
public:
    User(const std::string& id, const std::string& name, 
         const std::string& email, const std::string& password);
    ~User() = default;
    std::string getUserId() const;
    std::string getUsername() const;
    std::string getEmail() const;
    std::string getPasswordHash() const;
    std::time_t getCreatedDate() const;
    std::time_t getLastLogin() const;
    bool isActive() const;
    void setUsername(const std::string& name);
    void setEmail(const std::string& email);
    void setPasswordHash(const std::string& hash);
    void setLastLogin(std::time_t time);
    void setActive(bool active);
    void updateLastLogin();
    std::string getUserInfo() const;
};

#endif
