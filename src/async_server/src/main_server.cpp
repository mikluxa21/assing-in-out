#include "async_server/InterfaceServer.h"

int main(int argc, const char **argv)
{
    InterfaceServer interfaceServer(argc, argv);
    return interfaceServer.exec();
}