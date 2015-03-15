#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<inttypes.h>
#include<signal.h>
#include<linux/sched.h>
#include "rdstc.h"
#include "config.h"

#define STACK_SIZE 1024


void function(void){
    //printf("hello world!\n");
    _exit(0);
}

int main(){

    int tid;
    unsigned long long int st,et,t=0;
    int i;
    
    void * stack = malloc(STACK_SIZE);
    // Process creation time
    for(i=0; i<ITERATIONS; i++){
        st = rdtsc();
        tid = clone(function, stack + STACK_SIZE, SIGCHLD|CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FILES, NULL);
        et = rdtsc();
        waitpid(tid,0,0);
        t = t + (et-st);
    }
    printf("%f\n", (t/(ITERATIONS*CPU_FREQ)) - TIME_MEASUREMENT_OVERHEAD);
    free(stack);
    return 0;
}
