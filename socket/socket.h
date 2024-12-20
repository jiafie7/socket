#pragma once

#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

#include "utility/log_system.h"

using namespace melon::utility;

namespace melon
{
  namespace socket
  {
    class Socket
    {
    public:
      Socket();
      Socket(int socket_fd);
      ~Socket();
      
      bool bind(const std::string& ip, int port);
      bool listen(int backlog);
      bool connect(const std::string& ip, int port);
      int accept();
      int send(const char* buf, int len);
      int recv(char* buf, int len);
      void close();

    protected:
      std::string m_ip;
      int m_port;
      int m_socket_fd;
    };
  }
}