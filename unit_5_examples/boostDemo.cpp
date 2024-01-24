//
// Created by Or Hasson on 24/01/2024.
//

#include "headers/boostDemo.h"
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

void testClientBoostAsio() {
    char address[] = "127.0.0.1";
    char port[] = "1234";
    boost::asio::io_context io_context;
    tcp::socket s(io_context);
    tcp::resolver resolver(io_context);
    boost::asio::connect(s, resolver.resolve(address, port));
    const int max_length = 1042;
    char request[max_length];
    std::cout << "Enter message: ";
    std::cin.getline(request, max_length);
    boost::asio::write(s, boost::asio::buffer(request, max_length));
}

void testServerBoostAsio() {
    int port = 1234;
    const int max_length = 1024;
    boost::asio::io_context io_context;
    tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), port));
    tcp::socket sock = a.accept();

    char data[max_length];
    size_t length = boost::asio::read(sock, boost::asio::buffer(data, max_length));
    std::cout << "Received message: " << data << std::endl;
}


