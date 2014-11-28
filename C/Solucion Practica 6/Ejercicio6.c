#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

/*--------------------------------------------------------------*/
/*gestion de señales en proceso padre (handler)*/
void gestion_padre (int segnal) 
{
	char msg[50];
	printf ("--------------\n ");
	printf ("Estas en padre\n ");
	printf ("Que quieres enviar a hijo: ");
	fflush(stdin);
	gets(msg);
	printf ("send %s  \n",msg);
	
}

/*gestion de señales en proceso hijo (handler)*/
void gestion_hijo (int segnal) 
{
	char msg[50];
	printf ("--------------\n ");
	printf ("Estas en hijo\n ");
	printf ("Que quieres enviar a padre: ");
	fflush(stdin);
	//	scanf("%s",msg);
	gets(msg);
	printf ("send %s  \n",msg);
}
/*--------------------------------------------------------------*/

int main(){
	int pid_padre,pid_hijo;
	pid_padre=getpid();
	pid_hijo=fork(); //se crea al hijo

	switch(pid_hijo){
		case -1: //error
			printf("Error al crear proceso  hijo..\n");
			exit(-1);	
		
		case 0: //hijo
			signal(SIGUSR1,gestion_hijo); //tratamiento señal en proceso hijo
			while (1) { //bucle infinito
				sleep(1);
				kill(pid_padre,SIGUSR1); //envia señal a padre
				}
			break;

		default: //padre
			signal(SIGUSR1,gestion_padre); //tratamiento señal en proceso padre
			while (1) { //bucle infinito
				pause(); //padre espera hasta recibir señal hijo (se ejecutar primero)
				//sleep(1);
				kill(pid_hijo,SIGUSR1); //envia señal a hijo
				}
			break;
		}//fin switch

return 0;
}//fin programa
