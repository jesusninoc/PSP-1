#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

/*--------------------------------------------------------------*/
void manejador (int segnal) 
{
	printf ("Soy el manejador del padre\n");
}

int main()
{
	int pid_hijo, pid_padre;
	pid_padre=getpid();
	pid_hijo=fork(); //creamos hijo
	switch (pid_hijo)
		{
		case -1:
			printf ("ERROR al crear hijo.. \n");
			exit(-1);
		
		case 0: //hijo
			sleep(1);
			kill(pid_padre,SIGUSR1); //envia señal a padre
			sleep(1);
			kill(pid_padre,SIGUSR1); //envia señal a padre
			sleep(1);
			kill(pid_padre,SIGUSR1); //envia señal a padre
			sleep(1);
			kill(pid_padre, SIGKILL);
		default: //Padre
			signal (SIGUSR1, manejador); //establezco manejador señal en padre
			while(1){
				};
			break;	
		break;
		}
	
return 0;
}
