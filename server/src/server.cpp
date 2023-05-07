#include "server.hpp"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

Server::Server(boost::asio::io_context& io_context, unsigned short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    start_accept();
}

void Server::start_accept() {
    auto new_connection = std::make_shared<Connection>(acceptor_.get_executor().context());
    acceptor_.async_accept(new_connection->socket(),
        [this, new_connection](const boost::system::error_code& error) {
            if (!error) {
                connections_.insert(new_connection);
                new_connection->start();
                start_accept();
            }
        });
}

Server::Connection::Connection(boost::asio::io_context& io_context)
    : socket_(io_context) {
}

void Server::Connection::start() {
    read();
}

void Server::Connection::read() {
    socket_.async_read_some(boost::asio::buffer(buffer_),
        [this, shared_this = shared_from_this()](const boost::system::error_code& error, std::size_t length) {
            if (!error) {
                // Здесь можно добавить обработку прочитанных данных (например, отправка сообщений другим клиентам)
                std::cout.write(buffer_.data(), length);
                read();
            }
        });
}

tcp::socket& Server::Connection::socket() {
    return socket_;
}
