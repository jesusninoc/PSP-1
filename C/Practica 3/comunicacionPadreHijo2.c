#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	pid_t pid;
	char saludoPadre[]="Hello dad.";
	char buffer[20];
	int opcion[1];

	printf("Escribe 1 si quires hablar como padre\n");
	printf("Escribe 2 si quires hablar como hijo\n");

	scanf("%d",opcion);
	//printf("%s\n",opcion );

	if(opcion[0]==1){
		printf("Escribe el mensaje que quires que le envie el padre al hijo\n");
		scanf("%s",saludoPadre);

		pipe(fd);

		pid=fork();

		switch(pid){
			case -1: //error
				printf("no se ha podido crear el hijo\n");
				exit(-1);
			case 0: //hijo escribe descriptor 1
				close (fd[0]);
				//read (fd[1],buffer,sizeof(buffer));
				write (fd[1],saludoPadre, strlen(saludoPadre));
				printf("el padre le dice al hijo %s \n",saludoPadre);
				
				break;
			default: //padre lee de descriptor 0
				wait(NULL);
				close (fd[1]);
				//write (fd[0],saludoPadre, strlen(saludoPadre));
				read (fd[0],buffer,sizeof(buffer));
				printf("el hijo recibe un mensaje del padre %s\n",buffer);
				//wait(NULL);
				break;
		}
	}else if (opcion[0]==2){
		printf("Escribe el mensaje que quires que le envie el hijo al padre\n");
		scanf("%s",saludoPadre);

		pipe(fd);

		pid=fork();

		switch(pid){
			case -1: //error
				printf("no se ha podido crear el hijo\n");
				exit(-1);
			case 0: //hijo escribe descriptor 1
				close (fd[0]);
				read (fd[1],buffer,sizeof(buffer));
				//write (fd[1],saludoPadre, strlen(saludoPadre));
				printf("el hijo le dice al padre %s \n",saludoPadre);
				
				break;
			default: //padre lee de descriptor 0
				wait(NULL);
				close (fd[1]);
				write (fd[0],saludoPadre, strlen(saludoPadre));
				//read (fd[0],buffer,sizeof(buffer));
				printf("el padre recibe un mensaje del hijo %s\n",buffer);
				//wait(NULL);
				break;
		}
	}		
}