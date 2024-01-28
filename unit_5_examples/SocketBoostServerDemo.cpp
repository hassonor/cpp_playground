//
// Created by Or on 1/28/2024.
//

#include "headers/SocketBoostServerDemo.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

const int max_length = 1024;

void clear(char message[], int length) {
    for (int i = 0; i < length; i++) {
        message[i] = '\0';
    }
}

void session(tcp::socket sock) {
    try {
        for (;;) {
            char data[max_length];
            size_t reply_length = boost::asio::read(sock,
                                                    boost::asio::buffer(data, max_length));

            std::cout << "Received message: " << data << std::endl;

            clear(data, max_length);
            std::cout << "Enter message: ";
            std::cin.getline(data, max_length);
            boost::asio::write(sock, boost::asio::buffer(data, max_length));
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server(boost::asio::io_context& io_context, unsigned short port) {
    tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), port));
    for (;;) {
        session(a.accept());
    }
}

int socketBoostServerDemoRun(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: blocking_tcp_echo_server <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;
        server(io_context, std::atoi(argv[1]));
    }

    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}


