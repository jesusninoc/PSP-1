#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

pid_t pid, pid1, pid2;
int status;

printf("Creo proceso 1.\n");
pid=fork();

if (pid==0){
	//waitpid(pid1, &status, 0);
	sleep(2);
	printf("Paso puente proceso 1 y termina.\n");
	exit(0);
}else{
	printf("Creo proceso 2.\n");
	pid1=fork();
	if(pid1==0){
		//waitpid(pid2, &status, 0);
		sleep(1);
		
		printf("Paso puente proceso 2 y termina.\n");
		exit(0);
	}else{
		printf("Creo proceso 3.\n");
		pid2=fork();
		if(pid2==0){
			printf("Paso puente proceso 3 y termina.\n");
			exit(0);
		}
	}
}
sleep(3);
return 0;
}


