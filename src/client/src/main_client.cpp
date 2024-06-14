#include "client/Interface.h"

int main(int argc,const char** argv)
{
    Interface interface(argc, argv);
    return interface.exec();
}
