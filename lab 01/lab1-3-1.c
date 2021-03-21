#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int status;
    char *LocalE[]={"./echo,", argv[1], NULL};
    char *LocalB[]={"./bomdia",NULL};
    while (1) { /* repeat forever */
        if (fork() == 0) { 
            if(fork() == 0) { /*processo neto*/
                printf("neto foi criado\n");
                execve("./echo", LocalE, NULL); /* execute command */
                printf("processo neto vai terminar\n");
                exit(0);
            }
            else{ /* processo filho*/
                printf("filho foi criado\n");
                execve("./bomdia", LocalB, NULL); /* execute command */
                printf("processo Filho vai terminar\n");
                wait(&status); /* wait for child to exit */
                exit(0);
            }
        }
        else{ /* processo pai*/
            printf("pai foi criado\n");
            execl("/bin/sh", "sh", "-c", "/bin/cat algo.txt", NULL);
            printf("processo pai vai terminar\n");
            wait(&status); /* wait for child to exit */
            exit(0);
        }
            
    }       
    return 0;     
} 
