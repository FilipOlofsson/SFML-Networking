#include <SFML/Network.hpp>
#include <iostream>

int main()
{
    sf::UdpSocket socket;
    std::size_t received;
    if(socket.bind(54000) != sf::Socket::Done) {
        printf("Error binding to the socket.");
    }
    sf::IpAddress IP;
    unsigned short port;
    while(true) {
        char data[1000];
        if(socket.receive(data, 1000, received, IP, port) != sf::Socket::Done) {
            printf("Error receiving data.");
        }
        for(int i = 0; i < 1000; i++) {
            if(data[i] != '@') {
                std::cout << data[i];
            }
        }
        std::cout << std::endl;
    }
}