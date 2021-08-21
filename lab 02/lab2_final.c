/*
Tharik Lourenço
Suemy Inagaki
SO - Lab2 - Memoria compartilhada
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAM_TOTAL 4000
#define NUMPROC 4
#define numP 80

int main( void ){ 

    int segmento,*p;
    segmento=shmget(IPC_PRIVATE, (TAM_TOTAL*sizeof(int)) ,IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    if(segmento<0){
        printf("Shmget erro!\n");
        exit(1);
    }
    p = (int*)shmat(segmento,0,0);
    for(int t=0;t<TAM_TOTAL;t++){
        if (t%100 ==0) 
            p[t] = 80;
        else
            p[t]= rand()%1000;
    }
    
    
    for (int i = 0; i < NUMPROC; ++i)
    {
        if (fork() == 0){    
            printf("começo do processo filho %d\n",getpid());

            /*separa igualmente a qtd de elementos para cada processo*/
            int start = 0;
            for(int j=0;j<i;++j){
                start += (TAM_TOTAL+1-start) /(NUMPROC - j);
            }
            int tam = (TAM_TOTAL+1-start) /(NUMPROC - i);
            int end = start + tam;

            for(int n = start ;n < end;n++){
                printf("processo %d (pai:%d)- pesquisando[%d] em %d : %d\n" , getpid(), getppid(),numP, n,p[n] );
                if (numP == p[n]){
                    printf("processo %d (pai:%d)- achou o numero %d no espaço %d\n" , getpid(), getppid(),numP ,n);
                }
            }
                
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < 3; ++i)
        wait(NULL);
    printf("processo pai vai terminar !!!\n");
    exit(0);
}