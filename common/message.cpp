#include "message.hpp"

Message::Message(int id, int sender_id, int recipient_id, const std::string& text)
    : id_(id), sender_id_(sender_id), recipient_id_(recipient_id), text_(text) {}

int Message::get_id() const {
    return id_;
}

int Message::get_sender_id() const {
    return sender_id_;
}

int Message::get_recipient_id() const {
    return recipient_id_;
}

const std::string& Message::get_text() const {
    return text_;
}

void Message::set_text(const std::string& text) {
    text_ = text;
}
