#include <SFML/Network.hpp>
#include <string.h>
#include <iostream>

using namespace sf;

int main()
{
    IpAddress target = "127.0.0.1";
    UdpSocket socket;
    std::string toSend;
    while(true) {
        char data[1000];
        for(int i = 0; i < 1000; i++) {
            data[i] = '@';
        } 
        std::getline(std::cin, toSend);
        strcpy(data, toSend.c_str());
        if(socket.send(data, 1000, target, 54000) != sf::Socket::Done) {
            printf("Error sending data.");
        }
    }
}