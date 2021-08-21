/*
lab 3
Tharik Lourenco
Suemy Inagaki
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2
#define TAM_TOTAL 13

int v[TAM_TOTAL] = {1,0,0,0,1,0,0,0,1,0,0,0,1};

void *procura(void *threadid)
{
    int i;
    int start = (int) threadid * TAM_TOTAL/NUM_THREADS;
    int stop = ((int) threadid +1) * TAM_TOTAL/NUM_THREADS;
    for(i=start; i<stop; i++){
        printf("thread num : %d -> procurando no endedereço %d , numero: %d achou? %s\n",(int) threadid,i, 1 , (v[i] == 1)?"SIM":"nao");
    }
        pthread_exit(NULL); 
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int t;
    for(t=0;t < NUM_THREADS;t++)
    {
    printf("Creating thread %d\n", t);
        pthread_create(&threads[t], NULL, procura,(void *) t);
    }
    for(t=0; t < NUM_THREADS; t++)
        pthread_join(threads[t],NULL); /* wait for all the threads to terminate*/
} 