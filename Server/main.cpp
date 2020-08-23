#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include "ChatServer.h"
#include "tester.h"
using namespace std;

int detectIP()
{

    int server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0)
        cout << "Error in server Creating\n";
    else
        cout << "Server Created\n";
    struct sockaddr_in my_addr, peer_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("8.8.8.8");
    my_addr.sin_port = htons(53);
    if (bind(server, (struct sockaddr *)&my_addr, sizeof(struct sockaddr_in) == 0))
    {
        cout << "Binded correctly \n";
    }
    else
    {
        cout << "unable to bind";
    }
    int con = connect(server, (struct sockaddr *)&my_addr, sizeof my_addr);
    if (con == 0)
    {
        cout << "client connected\n";
    }
    else
    {
        cout << "error in connection\n";
    }
    return server;
}
int main()
{
    string buffer1, buffer2;
    int server = detectIP();
    struct sockaddr_in serverIP;
    socklen_t namelen = sizeof(serverIP);
    int whatthis = getsockname(server, (struct sockaddr *)&serverIP, &namelen);
    cout << "whatthis: " << whatthis << endl;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(serverIP.sin_addr), ip, INET_ADDRSTRLEN);
    // cout << "serverIP: " << ip << endl;

    ChatServer::Server sv;
    string serverIp(ip);
    sv.setIp(serverIp);
    sv.setSock(server);

    cout << "Server IP return from DNS: " << sv.getIp() << endl;
    cout << "random: " << randomx() << endl;
    return 0;
}