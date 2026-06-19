#include "../include/User.h"
#include <sstream>
#include <iomanip>

User::User(const std::string& id, const std::string& name,
           const std::string& em, const std::string& password)
    : user_id(id), username(name), email(em), password_hash(password) {
    created_date = std::time(nullptr);
    last_login = created_date;
    is_active = true;
}

std::string User::getUserId() const { return user_id; }
std::string User::getUsername() const { return username; }
std::string User::getEmail() const { return email; }
std::string User::getPasswordHash() const { return password_hash; }
std::time_t User::getCreatedDate() const { return created_date; }
std::time_t User::getLastLogin() const { return last_login; }
bool User::isActive() const { return is_active; }

void User::setUsername(const std::string& name) { username = name; }
void User::setEmail(const std::string& em) { email = em; }
void User::setPasswordHash(const std::string& hash) { password_hash = hash; }
void User::setLastLogin(std::time_t time) { last_login = time; }
void User::setActive(bool active) { is_active = active; }

void User::updateLastLogin() {
    last_login = std::time(nullptr);
}

std::string User::getUserInfo() const {
    std::stringstream ss;
    ss << "User: " << username << " (" << email << ")\n"
       << "Created: " << created_date << "\n"
       << "Last Login: " << last_login << "\n"
       << "Status: " << (is_active ? "Active" : "Inactive");
    return ss.str();
}
