#include "display.h"

int main()
{
    int i = 0;
    setup();
    while(1) 
    {
        display(0, i++%16);
        delay(.1);
    }
    return 0;
}
