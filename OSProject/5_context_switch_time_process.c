#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include "rdstc.h"
#include "config.h"

int pp[2];

int main() {

    int pid; // process id
    int p; // pipe
    int i, j = 5; // context switch ITERATIONS
    int data, status;

    unsigned long long int start_t, end_t, t;    

    p = pipe(pp);
    if (p < 0){
        perror("Pipe creattion failed");
        exit(1);
    }

    for (i=0; i<ITERATIONS; i++){
        pid = fork();
        if(pid < 0){
            perror("Child creation failed");
            exit(2);
        }

        if(pid == 0){
            // Child
            close(pp[0]);
            data = 10;
            read(pp[1], &data, sizeof(int));
            exit(0);
        }
        else {
            // parent
            close(pp[1]);
            start_t = rdtsc();
            write(pp[0], &j, sizeof(int));
            waitpid(pid,&status,0);
            end_t = rdtsc();
            t = t + (end_t - start_t);
        }
    }
    printf("%f\n",(t/(CPU_FREQ*ITERATIONS*2)) - TIME_MEASUREMENT_OVERHEAD);
}
