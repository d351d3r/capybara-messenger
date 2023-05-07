#include "database.hpp"
#include <iostream>

Database::Database(const std::string& db_filename) {
    if (sqlite3_open(db_filename.c_str(), &db_) != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db_) << std::endl;
        sqlite3_close(db_);
        db_ = nullptr;
    } else {
        // Initialize user and message tables
        // (user_id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT)
        // (message_id INTEGER PRIMARY KEY, sender_id INTEGER, recipient_id INTEGER, content TEXT)
    }
}

Database::~Database() {
    const char* create_users_table_sql =
    "CREATE TABLE IF NOT EXISTS users ("
    "user_id INTEGER PRIMARY KEY,"
    "username TEXT UNIQUE NOT NULL,"
    "password_hash TEXT NOT NULL,"
    "display_name TEXT);";

if (sqlite3_exec(db_, create_users_table_sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
    std::cerr << "Cannot create users table: " << sqlite3_errmsg(db_) << std::endl;
}

const char* create_messages_table_sql =
    "CREATE TABLE IF NOT EXISTS messages ("
    "message_id INTEGER PRIMARY KEY,"
    "sender_id INTEGER NOT NULL,"
    "recipient_id INTEGER NOT NULL,"
    "content TEXT NOT NULL,"
    "timestamp INTEGER NOT NULL);";

if (sqlite3_exec(db_, create_messages_table_sql, nullptr, nullptr, nullptr) != SQLITE_OK) {
    std::cerr << "Cannot create messages table: " << sqlite3_errmsg(db_) << std::endl;
}

    if (db_) {
        sqlite3_close(db_);
    }
}

bool Database::add_user(const User& user) {
    // Insert a new user into the user table
}

User Database::get_user(const std::string& username) {
    // Retrieve a user from the user table by username
}

std::vector<User> Database::get_users() {
    // Retrieve all users from the user table
}

bool Database::add_message(const Message& message) {
    // Insert a new message into the message table
}

std::vector<Message> Database::get_messages(int sender_id, int recipient_id) {
    // Retrieve all messages between sender and recipient from the message table
}
