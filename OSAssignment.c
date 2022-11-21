#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

double timeA;
double timeB;
double timeC;

void* countA(void* a){
    clock_t start_t, end_t; 
    start_t=clock();  
    for(long long i=1;i<pow(2,32);i++){ //2 raised to the power of 32 = 4294967296
        
    }
    end_t=clock();
    timeA=(double)(end_t-start_t)/(CLOCKS_PER_SEC*2);
    

}

void* countB(void* b){
    clock_t start_t, end_t;
    start_t=clock();
    for(long long i=1;i<pow(2,32);i++){
        
    }
    end_t=clock();
    
    timeB=(double)(end_t-start_t)/(CLOCKS_PER_SEC*2);
    
}

void* countC(void* c){
    clock_t start_t, end_t;
    start_t=clock();
    for(long long i=1;i<pow(2,32);i++){
    
    }
    end_t=clock();
    timeC=(double)(end_t-start_t)/(CLOCKS_PER_SEC*2);
    

}

void main(){
    FILE *fp;
    fp = fopen("data.csv","a+");
    pthread_t ThrA;
    pthread_t ThrB;
    pthread_t ThrC;
    
    struct sched_param paramA;
    pthread_create(&ThrA, NULL, &countA, NULL);
    paramA.sched_priority=0;
    pthread_setschedparam(ThrA,SCHED_OTHER,&paramA);

    struct sched_param paramB;
    pthread_create(&ThrB, NULL, &countB, NULL);
    paramB.sched_priority=1;
    pthread_setschedparam(ThrB,SCHED_RR,&paramB);

    struct sched_param paramC;
    pthread_create(&ThrC, NULL, &countC, NULL);
    paramC.sched_priority=1;
    pthread_setschedparam(ThrC,SCHED_FIFO,&paramC);

    pthread_join(ThrA, NULL);
    pthread_join(ThrB, NULL);
    pthread_join(ThrC, NULL);

    fprintf(fp,"%f",timeA);fprintf(fp,",");
    fprintf(fp,"%f",timeB);fprintf(fp,",");
    fprintf(fp,"%f",timeC);fprintf(fp,"\n");
    fclose(fp);
}