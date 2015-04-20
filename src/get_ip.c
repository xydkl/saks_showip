#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
//获取地址
//返回IP地址字符串
//返回：0=成功，-1=失败
int getlocalip(char* outip)
{
  int i=0;
  int sockfd;
  struct ifconf ifconf;
  char buf[512];
  struct ifreq *ifreq;
  char* ip;
  //初始化ifconf
  ifconf.ifc_len = 512;
  ifconf.ifc_buf = buf;
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
    {
      return -1;
    }
  ioctl(sockfd, SIOCGIFCONF, &ifconf); //获取所有接口信息
  close(sockfd);
  //接下来一个一个的获取IP地址
  ifreq = (struct ifreq*)buf;
  for(i=(ifconf.ifc_len/sizeof(struct ifreq)); i>0; i--)
    {
      ip = inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr);
      if(strcmp(ip,”127.0.0.1″)==0) //排除127.0.0.1，继续下一个
	{ ifreq++; continue; }
      strcpy(outip,ip);
      return 0;
    }
  return -1;
}
