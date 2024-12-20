#include "socket/socket.h"

using namespace melon::socket; 

int main()
{
  Singleton<LogSystem>::getInstance()->open("./../server.log");
  Socket server;
  server.bind("127.0.0.1", 7777);
  server.listen(1024);

  while (true)
  {
    int conn_fd = server.accept();
    if (conn_fd < 0)
      return 1;

    Socket client(conn_fd);
    
    char buf[1024] = {0};
    client.recv(buf, sizeof(buf));
    printf("recv: %s\n", buf);

    std::string msg = "hi, I am server!";
    client.send(msg.c_str(), msg.size());
  }

  return 0;
}
