#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rdstc.h"
#include "config.h"

#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB
#define SIZE_OF_MEMORY 1 * GB
#define ITR 5
#define FILES 6


#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[]){


    int fd, fd_file_cache;
    char *data = "3";
    char arr[9] = "file_";
    char *size[]= {"1", "2", "3", "4", "5", "6", "7", "8"};
    char *f_name[5];
    int i,j;
    char *buf[1024];
    long long unsigned int s_t, e_t, t=0, s,e;


    for (i = 0; i < FILES; i++){

        f_name[i] = strcat(arr, size[i]);
        printf("File %d: %s\n", i, f_name[i]);

        if ((fd = open(f_name[i], O_RDONLY)) == -1){
            handle_error("open");
        }

        s_t = rdtsc();
	for(j=0; j<ITR; j++) {
        	while(read(fd, buf, 1024) != 0);
/*		if (j == 1)
			//printf("************************\n");
        	while(1) {
        		s = rdtsc();
        		t = read(fd, buf, 1024);
			if (t == 0)
				break;
        		e = rdtsc();
			//if (i == 0)
				//printf("%f\n", (e-s)/CPU_FREQ);
		}*/
		lseek(fd, 0, SEEK_SET);
	}
        e_t = rdtsc();

        printf("Time required to read a %d file is %f\n", i, ((e_t - s_t)/ITR)/CPU_FREQ);

        arr[strlen(arr) - strlen(size[i])] = '\0';
	close(fd);

	// drop file cache
	sync();
	fd_file_cache = open("/proc/sys/vm/drop_caches", O_WRONLY);
	write(fd_file_cache, data, sizeof(char));
	close(fd_file_cache);
	sync();
    }
    
    return 0;
    
}
