#include "client.hpp"
#include <iostream>
#include <boost/asio.hpp>

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            std::cerr << "Usage: client <host> <port>" << std::endl;
            return 1;
        }

        const std::string host(argv[1]);
        unsigned short port = static_cast<unsigned short>(std::stoi(argv[2]));
        boost::asio::io_context io_context;
        Client client(io_context, host, port);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
