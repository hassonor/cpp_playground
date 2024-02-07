
// Created by Or Hasson on 07/02/2024.

#include "server_winsock.h"
#include <iostream>

// Platform-specific includes and initialization
#ifdef _WIN32
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")
#else

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring> // For memset on non-Windows

#endif

#define PORT 8080

void initializeSockets() {
#ifdef _WIN32
    WSAData wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        exit(1);
    }
#endif
}

void cleanupSockets() {
#ifdef _WIN32
    WSACleanup();
#endif
}

int createSocket() {
#ifdef _WIN32
    return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
#else
    return socket(AF_INET, SOCK_STREAM, 0);
#endif
}

void closeSocket(int sock) {
#ifdef _WIN32
    closesocket(sock);
#else
    close(sock);
#endif
}

void testWinSocketDemo() {
    initializeSockets();

    int s = createSocket();
    if (s < 0) {
        std::cerr << "Socket creation failed.\n";
        cleanupSockets();
        return;
    }

    struct sockaddr_in sa = {};
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(PORT); // Translate the port to big-endian

    if (bind(s, (struct sockaddr *) &sa, sizeof(sa)) < 0) {
        std::cerr << "Bind failed.\n";
        closeSocket(s);
        cleanupSockets();
        return;
    }

    if (listen(s, SOMAXCONN) < 0) {
        std::cerr << "Listen failed.\n";
        closeSocket(s);
        cleanupSockets();
        return;
    }

    std::cout << "Listening on port " << PORT << std::endl;

    while (true) {
        std::cout << "Waiting for clients to connect " << std::endl;
        int clientSocket = accept(s, NULL, NULL);
        if (clientSocket < 0) {
            std::cerr << "Accept failed.\n";
            continue; // Handle new connections even if accept fails
        }

        std::cout << "Client connected!" << std::endl;

        char clientMsg[1024] = {};
        int bytesReceived = recv(clientSocket, clientMsg, 1024, 0);
        if (bytesReceived <= 0) {
            std::cerr << "Receive failed or connection closed.\n";
            closeSocket(clientSocket);
            continue;
        }

        clientMsg[bytesReceived] = '\0'; // Ensure null termination
        std::cout << "Client sent: " << clientMsg << std::endl;

        // Construct and send the HTTP response
        std::string servMsg = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<!DOCTYPE html>\n<HTML><title>Hi from server</title><body><h1>Hi from server in defensive programming</h1></body></HTML>";
        send(clientSocket, servMsg.c_str(), servMsg.length(), 0);

        closeSocket(clientSocket);
    }

    closeSocket(s);
    cleanupSockets();
}
