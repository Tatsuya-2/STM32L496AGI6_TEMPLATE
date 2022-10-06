#include "common_inc.h"

extern Robot robot;

void CommonAsciiCmd(const char* _cmd, StreamSink& _responseChannel)
{
  std::string s(_cmd);
}

void OnUsbAsciiCmd(const char* _cmd, size_t _len, StreamSink& _responseChannel)
{
  /*---------------------------- ↓ Add Your CMDs Here ↓ -----------------------------*/

  /*---------------------------- ↑ Add Your CMDs Here ↑ -----------------------------*/
}

void OnUart2AsciiCmd(const char* _cmd, size_t _len, StreamSink& _responseChannel)
{
  /*---------------------------- ↓ Add Your CMDs Here ↓ -----------------------------*/

  /*---------------------------- ↑ Add Your CMDs Here ↑ -----------------------------*/
}
