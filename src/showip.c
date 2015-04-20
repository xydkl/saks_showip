#include "display.h"
#include "get_ip.h"
#include <stdio.h>

int main()
{
	char ip[20];
	int i;
	setup();
	for(i=0;i<10;++i) 
	{
		getlocalip(ip);
		showip(ip);
	}
	return 0;
}
