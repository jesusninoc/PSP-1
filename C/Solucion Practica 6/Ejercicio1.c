#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

pid_t pid;
pid=fork();
int status, i;

switch (pid){

	case -1:
		printf("Error no se ha podido crear el proceso hijo.\n");
		exit(-1);
	case 0:
		for (i=0;i<9;i++){ //mensaje hijo
			printf("Soy el proceso hijo.\n");
		}
		break;
	default:
		waitpid(pid, &status, 0); //espero que termine hijo
		printf("Mi proceso hijo ha terminado.\n"); //muestro mensaje
		for (i=0;i<9;i++){ //mensaje padre
			printf("Soy el proceso padre.\n");
		}
		
		break;

}
return 0;
}
