
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
  
int main() 
{ 
    int status;

    int sum1 =0;
    int sum2 =0;
    int sum3 =0;
    int i =0;
    int j =1000;
    int k =2000;
    if (fork() == 0) { /* child 1*/ 
        printf("processo 1 foi criado\n");
        for (i;i<=999;i++){
            sum1 +=i;
            printf("processo 1 (%d)\n", i);
        }
        printf("soma processo 1 (%d)\n", sum1);
        printf("processo 1 vai terminar\n");
        printf("pid proc1 = %d, pid do pai = %d\n", getpid(), getppid());
        exit(0);
    } 
    else if(fork() == 0) {  /* child 2*/ 
        printf("processo 2 foi criado\n");
        for (j;j<=1999;j++){
            sum2 +=j;
            printf("processo 2 (%d)\n", j);
        }
        printf("soma processo 2 (%d)\n", sum2);
        printf("processo 2 vai terminar\n");
        printf("pid proc2 = %d, pid do pai = %d\n", getpid(), getppid());
        exit(0);
    } 
    else if (fork() == 0) { /* child 3*/    
        printf("processo 3 foi criado\n");
        for (k;k<=2999;k++){
            sum3 +=k;
            printf("processo 3 (%d)\n", k);
        }
        printf("soma processo 3 (%d)\n", sum3);
        printf("processo 3 vai terminar\n");
        printf("pid proc3 = %d, pid do pai = %d\n", getpid(), getppid());
        exit(0); 
    }
    else if(fork() > 0){
        printf("processo pai\n");
        printf("pid do processo pai = %d\n", getpid());
    }    
    return 0; 
} 