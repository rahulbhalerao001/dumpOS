#include<stdio.h>
#include<time.h>
#include<iostream>
#include<vector>
#include "rdstc.h"
#include "config.h"

using namespace std;

#define KB 1024
#define MB 1024 * KB
#define MAX_ARRAY_SIZE 32*MB
#define STRIDE_SIZE 16

unsigned long long int access_time(unsigned long long int size){
    unsigned long long int no_of_reads = 100;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
        j = array[( i * STRIDE_SIZE) % len];
        j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(((CPU_FREQ*1000000)*1000000));
}


unsigned long long int access_time_1(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_2(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_3(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_4(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_5(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_6(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_7(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_8(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_9(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_10(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_11(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_12(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_13(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_14(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_15(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
unsigned long long int access_time_16(unsigned long long int size){
    unsigned long long int no_of_reads = MAX_ARRAY_SIZE;
    unsigned long long int s_t, e_t;
    unsigned long long int i, j, len;

    int *array = new int[(size)/sizeof(int)];
    len = (size)/sizeof(int);
    s_t = rdtsc();
    for(i=0; i < no_of_reads; i++){
       array[( i * STRIDE_SIZE) % len]++;
        //j++;
    }
    e_t = rdtsc();
   
//    delete array;
 
    return (e_t - s_t)/(CPU_FREQ*1000000);
}
int main(){

for(int i = 0; i < 20; i ++)
cout    <<  access_time_1(1024)<< "\t1" <<"\n"
        << access_time_2(1024 * 2) <<"\t2" << "\n"
        <<access_time_3(1024 * 4) <<"\t4" << "\n"
        <<access_time_4(1024 *8) <<"\t8" << "\n"
        << access_time_5(1024 * 16)<<"\t16" << "\n"
        << access_time_6(1024 * 28)<<"\t28" << "\n"
        << access_time_6(1024 * 30)<<"\t30" << "\n"
        << access_time_6(1024 * 32)<<"\t32" << "\n"
        << access_time_6(1024 * 34)<<"\t34" << "\n"
        << access_time_6(1024 * 36)<<"\t36" << "\n"
        << access_time_6(1024 * 56)<<"\t56" << "\n"
        << access_time_6(1024 * 60)<<"\t60" << "\n"
        << access_time_7(1024 * 64)<<"\t64" << "\n"
        << access_time_7(1024 * 68)<<"\t68" << "\n"
        << access_time_7(1024 * 72)<<"\t72" << "\n"
        <<access_time_8(1024 * 128)<<"\t128" << "\n"
        <<access_time_9(1024 * 256) <<"\t256" << "\n"
        << access_time_10(1024 * 512)<<"\t512" << "\n"
        <<access_time_11(1024 * 1024)<<"\t1024" << "\n"
        <<access_time_12(1024 * 2048)<<"\t2 MB" << "\n"
        << access_time_13(1024 * 4096)<<"\t4 MB" << "\n"
        <<access_time_14(1024 * 8192)<<"\t8 MB" << "\n"
        << access_time_15(1024 * 1024 * 16)<<"\t16 MB" << "\n"
        << access_time_15(1024 * 1024 * 18)<<"\t18 MB" << "\n"
        << access_time_15(1024 * 1024 * 20)<<"\t20 MB" << "\n"
        << access_time_15(1024 * 1024 * 22)<<"\t22 MB" << "\n"
        << access_time_16(1024 * 1024 * 32)<<"\t32 MB" << "\n"
        << access_time_16(1024 * 1024 * 64)<<"\t64 MB" << "\n" ;


/*    //Using vector of keys and vector of values instead of hashmap
    vector<unsigned long long int> k_array_size;			vector<float> v_measured_time;
     int total_array_size;
    
    for(unsigned long long int i = 1; i <= MAX_ARRAY_SIZE/1024; i *= 2) 
        k_array_size.push_back(i);
    
    total_array_size = k_array_size.size();
    v_measured_time.assign(total_array_size, 0);    // all times initialized to zero
   for(int iter = 0; iter < ITERATIONS; iter++)
        for(int i = 0; i < total_array_size; i++)

            v_measured_time[i] += access_time(1024 * k_array_size[i]);*/
     cout <<  access_time_1(1024)<< "\n" << access_time_2(1024 * 2) << "\n" <<access_time_3(1024 * 4) << "\n" <<access_time_4(1024 *8) << "\n" << access_time_5(1024 * 16)<< "\n" <<  access_time_6(1024 * 32)<< "\n"  << access_time_7(1024 * 64)<< "\n"  <<access_time_8(1024 * 128)<< "\n"  <<access_time_9(1024 * 256) << "\n" << access_time_10(1024 * 512)<< "\n" <<access_time_11(1024 * 1024)<< "\n"  <<access_time_12(1024 * 2048)<< "\n"  << access_time_13(1024 * 4096);
/*    cout << "Array size \t Access Time" << endl;
    for(int i = 0; i < total_array_size; i++){
	cout << k_array_size[i] << "\t" << ((v_measured_time[i])/ITERATIONS)/1000000 << endl;
    }
  */  
    return 0;
}
