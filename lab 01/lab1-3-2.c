
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
  
int main(int argc, char* argv[]) 
{ 
    char* const param[]={"/ bin / ls", "-l", "/ u / userid / dirname",NULL};
    int status;

    int sum1 =0;
    int sum2 =0;
    int sum3 =0;
    int i =0;
    int j =1000;
    int k =2000;
    char *LocalE[]={"./echo,", argv[1], NULL};
    char *LocalB[]={"./bomdia",NULL};
    if (fork() == 0) { /* child 1*/ 
        printf("processo 1 foi criado\n");
        execl("/bin/sh", "sh", "-c", "/bin/cat algo.txt", NULL);
        printf("processo 1 vai terminar\n");
        printf("pid proc1 = %d, pid do pai = %d\n", getpid(), getppid());
        exit(0);
    } 
    else { 
        if (fork() == 0) {  /* child 2*/ 
            printf("processo 2 foi criado\n");
            execve("./bomdia", LocalB, NULL); /* execute command */
            printf("processo 2 vai terminar\n");
            printf("pid proc2 = %d, pid do pai = %d\n", getpid(), getppid());
            exit(0);
        } 
        else {
            if (fork() == 0) { /* child 3*/ 
                printf("processo 3 foi criado\n");
                execve("./echo", LocalE, NULL); /* execute command */
                printf("processo 3 vai terminar\n");
                printf("pid proc3 = %d, pid do pai = %d\n", getpid(), getppid());
                exit(0); 
            }
            /*else{
                printf("processo pai\n");
                printf("pid do processo pai = %d\n", getpid());
            }*/
        }
        
        
    }

    
    return 0; 
} 