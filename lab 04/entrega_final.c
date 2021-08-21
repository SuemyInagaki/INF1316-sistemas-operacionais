/*
Tharik Lourenço
Suemy Inagaki
Lab 04 Sinais
Entrega Final
Sistemas Operacionais
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define EVER ;;
#define NUMPROC 4

void trata_SIGTSTP(int signum);
void trata_SIGCONT(int signum);

void trata_SIGTSTP(int signum) {
  printf("processo %d parado.\n", getpid()); 
  signal(SIGCONT, trata_SIGCONT);
  signal(SIGTSTP, SIG_DFL);
  raise(SIGTSTP); 
}

void trata_SIGCONT(int signum) {
  printf("processo %d continue\n", getpid()); 
  signal(SIGTSTP, trata_SIGTSTP);
  signal(SIGCONT, SIG_DFL);
  raise(SIGCONT); 
}


int main (int argc, char *argv[]){
    pid_t filhopid[NUMPROC];
    pid_t pid;
    for (int i=0 ;i<NUMPROC;i++){
        pid = fork();
        filhopid[i] = pid; 
        signal(SIGTSTP, trata_SIGTSTP);
        signal(SIGCONT, trata_SIGCONT);
        if (pid < 0){
	        fprintf(stderr, "Erro ao criar filho\n");
	        exit(-1);
	    }
	    if (pid == 0){ /* child */
	        printf("Filho %d criado pid: %d\n", i, getpid());
	        for(EVER); 
	    }
    } 
    /* parent */
    for(int j =0; j<20; j++){
        printf("tentando - %d\n", j+1);
        for(int i=0 ;i<NUMPROC ;i++){
            kill(filhopid[i], SIGCONT);
            sleep(1);
            kill(filhopid[i], SIGTSTP);
        }
    }
    for(int i=0 ;i<NUMPROC;i++)
        kill(filhopid[i], SIGKILL);
    
    return 0;
}


