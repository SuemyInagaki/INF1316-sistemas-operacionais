#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    
    int status;

    while (1) { /* repeat forever */
        int sum1 =0;
        int sum2 =0;
        int sum3 =0;
        int i =0;
        int j =1000;
        int k =2000;
        if (fork() == 0) { 
            if(fork() == 0){ /* é o processo neto */
            	printf("Neto foi criado\n");
            	for (k=2000;k<=2999;k++){
	                sum3 +=k;
	                printf("neto (%d)\n", k);
	            }
            printf("soma neto (%d)\n", sum3);
            printf("processo neto vai terminar\n");
            exit(0);
            }
            else { /* é o processo filho */
            	printf("Filho foi criado\n");
	            for (j=1000;j<=1999;j++){
	                sum2 +=j;
	                printf("filho (%d)\n", j);
	            }
	            printf("soma filho (%d)\n", sum2);
	            printf("processo filho vai terminar\n");
	            wait(&status); /* wait for child to exit */
	            exit(0);
            }
        }
        else{ /*é o processo pai*/
        	printf("Pai foi criado\n");
            for (i=0;i<=999;i++){
                sum1 +=i;
                printf("pai (%d)\n", i);
            }
            printf("soma pai (%d)\n", sum1);
            printf("processo pai vai terminar\n");
            wait(&status); /* wait for child to exit */
            exit(0);
        }
    }
 	return 0;  
}