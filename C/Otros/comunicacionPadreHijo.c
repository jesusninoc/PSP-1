#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	pid_t pid;
	char saludoPadre[]="Hello dad.";
	char buffer[20];


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
			printf("el hijo le dice al padre %s \n",saludoPadre);
			
			break;
		default: //padre lee de descriptor 0
			wait(NULL);
			close (fd[1]);
			//write (fd[0],saludoPadre, strlen(saludoPadre));
			read (fd[0],buffer,sizeof(buffer));
			printf("el padre recibe un mensaje del hijo %s\n",buffer);
			//wait(NULL);
			break;
	}
}