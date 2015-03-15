#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include "rdstc.h"
#include "config.h"

#define NUM_THREADS 2


pthread_mutex_t LOCK;
pthread_mutex_t TRIGGER;
pthread_cond_t COND;
volatile unsigned int cs_count = 0;

// Uptil now TRIGGER WAS LOCKED AND THEN RELEASED
void * function(void *id){
    int t_id = *(int *)id;

    // Wait for trigger from parent
    pthread_mutex_lock(&TRIGGER);
    pthread_mutex_unlock(&TRIGGER);		// So that both start at the same time
    // Get lock
    pthread_mutex_lock(&LOCK);			//only one thread passes in

    // Wake up other thread if context switch count is greater than 0
    if (cs_count > 0){
        pthread_cond_signal(&COND);
    }

    while(cs_count < ITERATIONS) {

        // Wait for other thread to wake up us
        cs_count++;					//Increment cs count
        pthread_cond_wait(&COND, &LOCK);		//release LOCK and wait for COND

        // wake up other thread
        pthread_cond_signal(&COND);        
    }
    pthread_mutex_unlock(&LOCK);
    pthread_exit(NULL);
}


int main(){

    pthread_t threads[NUM_THREADS];
    int rc, i,id1=1, id2=2;
    unsigned long long int t;
    
    pthread_mutex_init(&LOCK, NULL); 		// to protect CS
    pthread_mutex_init(&TRIGGER, NULL);		//This is to start at the same time
    pthread_cond_init(&COND, NULL);		// to wake each other

    pthread_mutex_lock(&TRIGGER);		//to stop the threads we are going to create		
					

    rc = pthread_create(&threads[0], NULL, function, (void*)&id1);	//create first thread
    if (rc){
        perror("Thread creation failed!");
    }
    rc = pthread_create(&threads[1], NULL, function, (void*)&id2);	//create second thread
    if (rc){
        perror("Thread creation failed!");
    }

    t = rdtsc();				// start time
    pthread_mutex_unlock(&TRIGGER);		// by releasing the trigger start the threads

    // Wait for threads to finish
    for(i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    t = rdtsc() - t;
    printf("%f\n",(t/(CPU_FREQ*ITERATIONS)) - TIME_MEASUREMENT_OVERHEAD);
    
    // Clean up
    pthread_mutex_destroy(&LOCK);
    pthread_mutex_destroy(&TRIGGER);
    pthread_cond_destroy(&COND);
    pthread_exit(NULL);
}


 
