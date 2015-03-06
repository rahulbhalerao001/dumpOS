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
    serv_addr.sin_port = htons(5015); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); //bind server address to socket 
    char msg[44] = "lmnpqrslmnpqrslmnpqrslmnpqrslmnpqrslmnpqrsi";
    char recvBuf[44];
    listen(listenfd, 10); // maximum number of client connections
    unsigned long long int s_t, e_t;
	int i;
	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 	// 3-way handshake
	if(recv(connfd, recvBuf, 44 * sizeof(char), 0) != 44){
			printf("send issue\n");

	}
	if(send(connfd, msg, sizeof(msg),0) != 44){
		printf("send issue\n");
	}
	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 	// 3-way handshake
	if(recv(connfd, recvBuf, 44 * sizeof(char), 0) != 44){
			printf("send issue\n");

	}


}	
