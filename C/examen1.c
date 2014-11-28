#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

void luzOn (int segnal) 
{
	printf ("Hijo enciende luz centro\n");
}

void luzOff (int segnal) 
{
	printf ("Hijo enciende luz centro\n");
}

int main(int argc, char const *argv[])
{
	
	int pid, pid2;
	pid2=getpid();
	
	int fd[2],seleccion[1];
	char buffer[1];

	printf("***************\n");
	printf("Proceso gestiona centro\n\n");
	printf("Introduce orden para gestion luz\n");
	printf("0. Salir\n");
	printf("1. Encender\n");
	printf("2. Apagar luz\n");
	scanf("%d",seleccion);

	pid=fork();

	switch(pid){
		case -1:
			printf("Error\n");
			exit(-1);
		case 0:
			kill(pid2,SIGUSR1);
			break;
		default:
			//printf("%d\n", seleccion[0]);
			if (seleccion[0]==1)
			{
				signal (SIGUSR1,luzOn);
				while(1){

				}
				exit(-1);
			}
			if(seleccion[0]==2){
				signal (SIGUSR1,luzOff);
				while(1){

				}
				exit(-1);
			}
			if (seleccion==0)
			{
				exit(-1);
			}
		
			
			break;

	}
	

	return 0;
}