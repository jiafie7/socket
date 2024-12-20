#include "socket/socket.h"

using namespace melon::socket;

int main()
{
  Singleton<LogSystem>::getInstance()->open("./../client.log");
  Singleton<LogSystem>::getInstance()->setConsole(false);
  Socket client;
  client.connect("127.0.0.1", 7777);

  std::string msg = "hi, I am client!";
  client.send(msg.c_str(), msg.size());

  char buf[1024] = {0};
  client.recv(buf, sizeof(buf));
  printf("recv: %s\n", buf);

  return 0;
}
