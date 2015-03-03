#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include "rdstc.h"
#include "config.h"
#include<sys/time.h>

/* Subtract the ‘struct timeval’ values X and Y,
   storing the result in RESULT.
   Return 1 if the difference is negative, otherwise 0. */

int
timeval_subtract (result, x, y)
     struct timeval *result, *x, *y;
{
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (x->tv_usec - y->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }

  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result->tv_sec = x->tv_sec - y->tv_sec;
  result->tv_usec = x->tv_usec - y->tv_usec;

  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}



int main(int argc, char *argv[])
{
    struct timeval startT, endT, result;
    int sockfd = 0, n = 0;
    char recvBuff[1024];

    struct sockaddr_in serv_addr; 

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)	// creates a socket.
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5002); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 


    gettimeofday(&startT, NULL);
    while( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) // connect socket with remote socket
    {
       printf("\n Error : Connect Failed \n");
       gettimeofday(&startT, NULL);
    } 
    unsigned long long int s_t, e_t;
    char msg[] = "abcdefg";
    char recvBuf[8];
    int i;
    for(i = 0; i < 600; i++){
	    s_t = rdtsc();
	    if(send(sockfd, msg, sizeof(msg),0) != 8)
		break;
	    if(recv(sockfd, recvBuf, 8 * sizeof(char), 0) != 8)
		break;
	    e_t = rdtsc();
	    printf("%f and %lu and %lu\n", (e_t - s_t)/(CPU_FREQ*1000000),  startT.tv_sec, startT.tv_usec);
	    sleep(0.1);	
   } 
    

/*    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 
*/
    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}
