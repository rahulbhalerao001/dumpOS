#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rdstc.h"
#include "config.h"


#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[]){

    int pid;
    char arr[9] = "file_";
    char *size[]= {"1", "2", "3", "4", "5", "6", "7", "8", "9" , "10"};
    char *f_name[5];
    int i, j, status;
    char *buf[4096];
    long long unsigned int s_t, e_t, t=0;
    int p_count = 0;

	printf("ARGC = %d, argv[1] = %s converted=%d\n", argc, argv[1], atoi(argv[1]));

    if (argc != 2){
	handle_error("./a.out <process count>");
    }
 
    p_count = atoi(argv[1]);

    // Process creation time
    for(i = 1, j=0; i <= p_count; i++,j++){
	    pid = fork();
	    if(pid == 0){
    	    int fd;
            
            //printf("Child: %d\n", i);
            sleep(2);
            f_name[j] = strcat(arr, size[j]);
            //printf("File %d: %s\n", j, f_name[j]);
            if ((fd = open(f_name[j], O_RDONLY)) == -1){
                handle_error("open");
            }

            posix_fadvise(fd, 0, 0, POSIX_FADV_RANDOM);
    
            s_t = rdtsc();
            while(read(fd, buf, 4096) != 0)
            e_t = rdtsc();

            //printf("Time required to read a block from %d file is %f\n", i, (e_t - s_t)/CPU_FREQ);
            printf("%f\n", (e_t - s_t)/CPU_FREQ);
            arr[strlen(arr) - strlen(size[j])] = '\0';

            close(fd);
	        exit(0);
	    }
	    else{
		   
	    }
    }

    sleep(20);
    wait(&status);
    
    return 0;
}
