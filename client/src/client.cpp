#include "client.hpp"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

Client::Client(boost::asio::io_context& io_context, const std::string& host, unsigned short port)
    : socket_(io_context) {
    tcp::resolver resolver(io_context);
    auto endpoint_iterator = resolver.resolve(host, std::to_string(port));
    connect(endpoint_iterator);
}

void Client::write(const std::string& msg) {
    boost::asio::async_write(socket_, boost::asio::buffer(msg),
        [this](const boost::system::error_code& error, std::size_t length) {
            if (!error) {
                // Здесь можно добавить обработку отправленного сообщения (например, логирование)
            }
        });
}

void Client::read() {
    socket_.async_read_some(boost::asio::buffer(buffer_),
        [this](const boost::system::error_code& error, std::size_t length) {
            if (!error) {
                std::cout.write(buffer_.data(), length);
                read();
            }
        });
}

void Client::connect(const tcp::resolver::results_type& endpoints) {
    boost::asio::async_connect(socket_, endpoints,
        [this](const boost::system::error_code& error, const tcp::endpoint&) {
            if (!error) {
                // Здесь можно добавить обработку успешного подключения (например, чтение и запись данных)
                read();
            }
        });
}
