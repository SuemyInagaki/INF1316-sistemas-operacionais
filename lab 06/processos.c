/*
Tharik Lourenço
Suemy Inagaki
SO - Lab6 - Semáforos
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>


#define NUMPROC 3
#define numP 80

int main( void ){ 

    int segmento;
    long long *soma;
    segmento=shmget(IPC_PRIVATE, sizeof (int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if(segmento<0){
        printf("Shmget erro!\n");
        exit(1);
    }
    soma = (long long*)shmat(segmento,0,0);
    *soma = 0;

    for (int i = 1; i <= NUMPROC; ++i)
    {
        if (fork() == 0){    
            printf("começo do processo filho %d\n",getpid());
            for(int j = 0; j < 5000000; j++){
                *soma+=i;
                //printf("%d\n", *soma);
            }            
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < 3; ++i)
        wait(NULL);
    printf("processo pai vai terminar !!!\n");
    printf("soma = %lld\n", *soma);    
    exit(0);
}