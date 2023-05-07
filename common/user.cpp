#include "user.hpp"

User::User(int id, const std::string& username, const std::string& password)
    : id_(id), username_(username), password_(password) {}

int User::get_id() const {
    return id_;
}

const std::string& User::get_username() const {
    return username_;
}

const std::string& User::get_password() const {
    return password_;
}

void User::set_password(const std::string& password) {
    password_ = password;
}
