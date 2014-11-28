#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd[2];
	pid_t pid1;
	int opcion[1];
	int status1;

	printf("Escribe 12 si quieres empezar con el primero \n");
	printf("Escribe 21 si quieres empezar con el segundo \n");

	scanf("%d",opcion);

	if(opcion[0]==12){
		pid1=fork();
		switch(pid1){
			case -1: //error
				printf("no se ha podido crear el proceso\n");
				exit(-1);
			case 0: 
				waitpid(pid1, &status1, 0);
				sleep(1); 
				printf("Soy el proceso 2 y termino \n");
				break;
			default: 
				sleep(1);
				printf("Soy el proceso 1 y termino \n");

				break;
		}
	}else if (opcion[0]==21){
		pid1=fork();
		switch(pid1){
			case -1: //error
				printf("no se ha podido crear el proceso\n");
				exit(-1);
			case 0:
				sleep(1); 
				printf("Soy el proceso 2 y termino \n");
				break;
			default:
				waitpid(pid1, &status1, 0);
				sleep(1);
				printf("Soy el proceso 1 y termino \n");
				break;
		}
		
	}		
}