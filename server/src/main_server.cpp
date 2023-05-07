#include "server.hpp"
#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: server <port>" << std::endl;
            return 1;
        }

        unsigned short port = static_cast<unsigned short>(std::stoi(argv[1]));
        boost::asio::io_context io_context;
        Server server(io_context, port);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
