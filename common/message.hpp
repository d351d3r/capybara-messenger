#include <string>

class Message {
public:
    Message(int id, int sender_id, int recipient_id, const std::string& text)
        : id_(id), sender_id_(sender_id), recipient_id_(recipient_id), text_(text) {}

    int get_id() const {
        return id_;
    }

    int get_sender_id() const {
        return sender_id_;
    }

    int get_recipient_id() const {
        return recipient_id_;
    }

    const std::string& get_text() const {
        return text_;
    }

    void set_text(const std::string& text) {
        text_ = text;
    }

private:
    int id_;
    int sender_id_;
    int recipient_id_;
    std::string text_;
};
