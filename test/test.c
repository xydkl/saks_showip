#include "display.h"
#include <stdio.h>

int main()
{
    int i;
    setup();
    for(i=0;i<100;i++)
    {
        display(0, i%16);
	display(1, i%8);
        delay(.1);
	sleep(1);
    }
    return 0;
}
