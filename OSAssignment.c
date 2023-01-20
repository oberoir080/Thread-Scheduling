#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables to store the time taken for each thread
double timeA;
double timeB;
double timeC;

// Thread function for counting from 1 to 2^32
void* countA(void* a){
    clock_t start_t, end_t; 
    // Record the start time
    start_t=clock();  
    for(long long i=1;i<pow(2,32);i++){ //2 raised to the power of 32 = 4294967296
        
    }
    // Record the end time
    end_t=clock();
    // Calculate the time taken for the thread and store it in global variable
    timeA=(double)(end_t-start_t)/(CLOCKS_PER_SEC*2);
    
}

// Thread function for counting from 1 to 2^32
void* countB(void* b){
    clock_t start_t, end_t;
    // Record the start time
    start_t=clock();
    for(long long i=1;i<pow(2,32);i++){
        
    }
    // Record the end time
    end_t=clock();
    // Calculate the time taken for the thread and store it in global variable
    timeB=(double)(end_t-start_t)/(CLOCKS_PER_SEC*2);
    
}

// Thread function for counting from 1 to 2^32
void* countC(void* c){
    clock_t start_t, end_t;
    // Record the start time
    start_t=clock();
    for(long long i=1;i<pow(2,32);i++){
    
    }
    // Record the end time
    end_t=clock();
    // Calculate the time taken for the thread and store it in global variable
    timeC=(double)(end_t-start_t)/(CLOCKS_PER_SEC*2);
    

}

int main(){
    FILE *fp;
    // Open a file to write the time taken by each thread
    fp = fopen("data.csv","a+");
    // Declare thread variables
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;
    
    struct sched_param paramA;
    // Create thread A and set its scheduling policy to SCHED_OTHER with priority 0
    pthread_create(&ThrA, NULL, &countA, NULL);
    paramA.sched_priority=0;
    pthread_setschedparam(ThrA,SCHED_OTHER,&paramA);

    struct sched_param paramB;
    // Create thread B and set its scheduling policy to SCHED_RR with priority 1
    pthread_create(&ThrB, NULL, &countB, NULL);
    paramB.sched_priority=1;
    pthread_setschedparam(ThrB,SCHED_RR,&paramB);

    struct sched_param paramC;
    // Create thread C and set its scheduling policy to SCHED_FIFO with priority 1
    pthread_create(&ThrC, NULL, &countC, NULL);
    paramC.sched_priority=1;
    pthread_setschedparam(ThrC,SCHED_FIFO,&paramC);

    // Wait for all threads to finish
    pthread_join(ThrA, NULL);
    pthread_join(ThrB, NULL);
    pthread_join(ThrC, NULL);

    // Write the time taken by each thread to the file
    fprintf(fp,"%f",timeA);fprintf(fp,",");
    fprintf(fp,"%f",timeB);fprintf(fp,",");
    fprintf(fp,"%f",timeC);fprintf(fp,"\n");
    // Close the file
    fclose(fp);
    return 0;
}
