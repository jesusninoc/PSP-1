#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

int a = atoi(argv[1]), status, i;
pid_t pid;

if(a==12){


		pid=fork();
		if(pid){
			printf("Soy el proceso 1 y termino\n");
		
		}else{
			wait(NULL);
			printf("Soy el proceso 2 y termino\n");
			exit(0);
		}
	

}else if(a==21){

	pid=fork();
	if (pid==0){
		printf("Soy el proceso 1 y termino\n");
	} else {

		printf("Soy el proceso 2 y termino\n");
		wait(NULL);
	}
	
}else{
	printf("Parametros incorrectos\n");
}

return 0;

}
