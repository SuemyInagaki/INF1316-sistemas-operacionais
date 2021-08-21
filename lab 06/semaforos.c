/*
Tharik Lourenço
Suemy Inagaki
SO - Lab6 - Semáforos
*/

#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/wait.h>
union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
};
// inicializa o valor do semáforo
int setSemValue(int semId);
// remove o semáforo
void delSemValue(int semId);
// operação P
int semaforoP(int semId);
//operação V
int semaforoV(int semId);
int main (int argc, char * argv[]){
	int i;
	int segmento;
	segmento = shmget (IPC_PRIVATE, sizeof (int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR); 
	if(segmento<0){
        printf("Shmget erro!\n");
        exit(1);
    }
	long long* soma = (long long*)shmat(segmento,0,0);
	*soma = 0;
	int semId;
	semId = semget (8752, 1, 0666 | IPC_CREAT);
	setSemValue(semId);
	for(int j = 1; j <= 3; j++){
		if(fork() == 0){
			semaforoP(semId);
			printf("começo do processo filho %d\n",getpid());
			for(long k = 0; k < 5000000; k++){
				*soma+=j;
			}
			semaforoV(semId);
			exit(EXIT_SUCCESS);
		}
	}
	for (int j = 1; j <= 3; ++j)
   		wait(NULL);

	sleep(10);
	delSemValue(semId);
	printf("Soma final = %lld\n", *soma);

	return 0;
}
int setSemValue(int semId){
	union semun semUnion;
	semUnion.val = 1;
	return semctl(semId, 0, SETVAL, semUnion);
}
void delSemValue(int semId){
	union semun semUnion;
	semctl(semId, 0, IPC_RMID, semUnion);
}
int semaforoP(int semId){
	struct sembuf semB;
	semB.sem_num = 0;
	semB.sem_op = -1;
	semB.sem_flg = SEM_UNDO;
	semop(semId, &semB, 1);
	return 0;
}
int semaforoV(int semId){
	struct sembuf semB;
	semB.sem_num = 0;
	semB.sem_op = 1;
	semB.sem_flg = SEM_UNDO;
	semop(semId, &semB, 1);
	return 0;
}
