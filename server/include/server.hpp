#include <iostream>
#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context& io_context, unsigned short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
        start_accept();
    }

private:
    void start_accept() {
        auto new_connection = std::make_shared<tcp::socket>(acceptor_.get_executor().context());
        acceptor_.async_accept(*new_connection, [this, new_connection](const boost::system::error_code& error) {
            if (!error) {
                // Обработка нового подключения
                std::cout << "Client connected: " << new_connection->remote_endpoint() << std::endl;
                
                // Здесь можно добавить логику обработки клиентского подключения, например, чтение и запись данных
                // ...

                // Начать прослушивание следующего подключения
                start_accept();
            }
        });
    }

    tcp::acceptor acceptor_;
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: server <port>" << std::endl;
        return 1;
    }

    try {
        boost::asio::io_context io_context;
        Server server(io_context, std::stoi(argv[1]));
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
