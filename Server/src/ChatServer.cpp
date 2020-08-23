#include "ChatServer.h"

int ChatServer::Server::getSock()
{
    return sock;
}
void ChatServer::Server::setSock(int x)
{
    sock = x;
}
string ChatServer::Server::getIp()
{
    return ip;
}
void ChatServer::Server::setIp(string serverIP)
{
    ip = serverIP;
}