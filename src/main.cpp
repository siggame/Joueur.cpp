#include "netLink.h"
#include <tclap/CmdLine.h>
#include "attrWrapper.hpp"

int main()
{
   //need to do this for Windows
   #ifdef WIN32
      netLink::init();
   #endif // WIN32
}
