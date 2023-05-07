#include <string>

class User {
public:
    User(int id, const std::string& username, const std::string& password)
        : id_(id), username_(username), password_(password) {}

    int get_id() const {
        return id_;
    }

    const std::string& get_username() const {
        return username_;
    }

    const std::string& get_password() const {
        return password_;
    }

    void set_username(const std::string& username) {
        username_ = username;
    }

    void set_password(const std::string& password) {
        password_ = password;
    }

private:
    int id_;
    std::string username_;
    std::string password_;
};
