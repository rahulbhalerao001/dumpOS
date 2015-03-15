#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<inttypes.h>
#include<signal.h>
#include "rdstc.h"
#include "config.h"

int main(){

    int pid, i;
    unsigned long long int t, total = 0;

    // Process creation time
    for(i = 0; i < ITERATIONS; i++){
	    t = rdtsc();
	    pid = fork();
	    if(pid == 0){
		    _exit(0);
	    }
	    else{
		    t = rdtsc() - t;
		    waitpid(pid, 0, 0);
		    total += t;
		   
	    }
    }
    printf("%f\n", (total/(CPU_FREQ * ITERATIONS) - TIME_MEASUREMENT_OVERHEAD));
    return 0;
}
