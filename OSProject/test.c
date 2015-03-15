#include<stdio.h>
#include<time.h>
#include<iostream>
#include<vector>
#include "rdstc.h"
#include "config.h"

using namespace std;

#define KB 1024
#define MB 1024 * KB
#define MAX_ARRAY_SIZE 64*MB
#define STRIDE_SIZE 16

int access_time(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
        j = ( i * STRIDE_SIZE) % len;
        ++array[j];
    }
    e_t = rdtsc();
   
    delete array;
 
    return (e_t - s_t)/CPU_FREQ;
}

int main(){
    //Using vector of keys and vector of values instead of hashmap
    vector<unsigned long long int> k_array_size;			vector<float> v_measured_time;
     int total_array_size;
    
    for(unsigned long long int i = 1; i <= (MAX_ARRAY_SIZE/1024); i *= 2) 
        k_array_size.push_back(i);
    
    total_array_size = k_array_size.size();
    v_measured_time.assign(total_array_size, 0);    // all times initialized to zero
    for(int iter = 0; iter < ITERATIONS; iter++)
        for(int i = 0; i < total_array_size; i++)
            v_measured_time[i] += access_time(1024 * k_array_size[i]);
        
    cout << "Array size \t Access Time" << endl;
    for(int i = 0; i < total_array_size; i++){
	cout << k_array_size[i] << "\t" << ((v_measured_time[i])/ITERATIONS)/1000000 << endl;
    }
    
    return 0;
}
