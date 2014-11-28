#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

/*--------------------------------------------------------------*/
/*gestion de señales con proceso hijo (handler)*/
void manejador (int segnal) 
{
	printf ("Padre recibe señal...%d\n",segnal);
}

int main()
{
	int pid_hijo,pid_padre;
	pid_padre = getpid();
	pid_hijo=fork(); //creamos hijo
	switch (pid_hijo)
		{
		case -1:
			printf ("ERROR al crear hijo.. \n");
			exit(-1);
		
		default: //padre
			signal (SIGUSR1,manejador); //establezco manejador señal en padre
			while(1){
				};
			break;
		case 0:
			sleep(1);
			kill(pid_padre,SIGUSR1); //envia señal a padre
			sleep(1);	
			kill(pid_padre,SIGUSR1); //envia señal a padre
			sleep(1);
			kill(pid_padre,SIGUSR1); //envia señal a padre
			sleep(1);
			kill(pid_padre,SIGKILL);	//Lo mata
		break;
		}
return 0;
}
