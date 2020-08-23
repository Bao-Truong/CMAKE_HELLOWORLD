#pragma once
#include "string.h"
#include "string"
using namespace std;
namespace ChatServer
{

    class Server
    {
    private:
        int sock;
        string ip;

    public:
        int getSock();
        void setSock(int x);
        void setIp(string x);
        string getIp();
    };
} // namespace ChatServer