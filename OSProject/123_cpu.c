#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include "rdstc.h"
#include "config.h"

void function0() {}
void function1(int a) {}
void function2(int a, int b) {}
void function3(int a, int b, int c) {}
void function4(int a, int b, int c, int d) {}
void function5(int a, int b, int c, int d, int e) {}
void function6(int a, int b, int c, int d, int e, int f) {}
void function7(int a, int b, int c, int d, int e, int f, int g) {}

int main(int argc, char **argv)
{
  //1. Measurement Overhead : Time Measurement Overhead
  int i,j;
  unsigned long long start,end,tsum=0, sum[8]={0,0,0,0,0,0,0,0};
  float timeMeasurementOverhead;
  for(i=0; i<ITERATIONS; i++) {
	start = rdtsc();
	end = rdtsc();
	tsum += end-start;
  }
  timeMeasurementOverhead = (unsigned long long int) tsum/(double)ITERATIONS;
  //printf("Time measurement overhead %ld\n", timeMeasurementOverhead);
  printf("%f\n", timeMeasurementOverhead);
  
  //1. Measurement Overhead : Loop Measurement Overhead
  tsum = 0; 
  for(i = 0; i < ITERATIONS; i++){
	start = rdtsc();
	for(j=0; j < 100;j++){}
  	end=rdtsc();
	tsum += end-start;
 }
  printf("%f\n", (tsum/(ITERATIONS)));

//  printf("Loop overhead: %llu\n", (end-start-timeMeasurementOverhead)/ITERATIONS);
  
  for(i=0; i<ITERATIONS; i++) {
     start=rdtsc();
     function0();
     end=rdtsc();
     //printf("%d %ld\n", 0,timespecDiff(&start[1], &start[0]));
     sum[0] += end-start;
   
   //2. Procedure Call Overhead
     start=rdtsc();
     function1(1);
     end=rdtsc();
     sum[1] += end-start;

     start=rdtsc();
     function2(1,2);
     end=rdtsc();
     sum[2] += end-start;

     start=rdtsc();
     function3(1,2,3);
     end=rdtsc();
     sum[3] += end-start;

     start=rdtsc();
     function4(1,2,3,4);
     end=rdtsc();
     sum[4] += end-start;

     start=rdtsc();
     function5(1,2,3,4,5);
     end=rdtsc();
     sum[5] += end-start;

     start=rdtsc();
     function6(1,2,3,4,5,6);
     end=rdtsc();
     sum[6] += end-start;

     start=rdtsc();
     function7(1,2,3,4,5,6,7);
     end=rdtsc();
     sum[7] += end-start;

  }
  for(i=0; i<8; i++) {
     printf("%f\n",(sum[i])/(ITERATIONS));
     //printf("Overhead with %d arguments: %ld\n", i, (long int) (sum[i]/(double)ITERATIONS) - timeMeasurementOverhead);
 }

  //3.System Call Overhead
  start=rdtsc();
  getpid();
  end=rdtsc();
//  printf("Overhead of system call getpid: %llu\n", end-start-timeMeasurementOverhead);
  printf("%f\n", (end-start-timeMeasurementOverhead)/(double)CPU_FREQ);
  start=rdtsc();
  time(NULL);
  end=rdtsc();
//  printf("Overhead of system call getpid: %llu\n", end-start-timeMeasurementOverhead);
  printf("%f\n", (end-start-timeMeasurementOverhead)/(double)CPU_FREQ);

  start=rdtsc();
  sleep(1);
  end=rdtsc();
//  printf("Overhead of system call getpid: %llu\n", end-start-timeMeasurementOverhead);
  printf("%f\n", ((end-start-timeMeasurementOverhead)/(double)CPU_FREQ)- 1000000000);

}
