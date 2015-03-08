#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "rdstc.h"
#include "config.h"
#include<sys/time.h>
int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);		//create a socket
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); //bind server address to socket 

    listen(listenfd, 10); // maximum number of client connections
    unsigned long long int s_t, e_t;
	char recvBuf[BATCH_SIZE];
	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 	// 3-way handshake
	long long int i = 0;
	s_t = rdtsc();	
	while(1){	
		if(recv(connfd, recvBuf, BATCH_SIZE *  sizeof(char), 0) != (BATCH_SIZE)){
			printf("recv issues\n");
			break;
		}
		i++;
	}
	e_t = rdtsc();	
	printf("Bandwidth %lf\n", (i*(BATCH_SIZE/((e_t - s_t)/(CPU_FREQ*1000000000))))/(1024*1024*1024));


}	
