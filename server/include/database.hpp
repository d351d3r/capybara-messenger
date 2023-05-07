#ifndef DATABASE_H
#define DATABASE_H

#include "user.hpp"
#include "message.hpp"
#include <sqlite3.h>
#include <vector>
#include <string>

class Database {
public:
    Database(const std::string& db_filename);
    ~Database();

    bool add_user(const User& user);
    User get_user(const std::string& username);
    std::vector<User> get_users();

    bool add_message(const Message& message);
    std::vector<Message> get_messages(int sender_id, int recipient_id);

private:
    sqlite3* db_;
};

#endif // DATABASE_H
