#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){

int fd[2];
int opcion;
pid_t pid;
char mensaje[80];
char buffer[80];
int i;

printf("¿Que tipo de comunicacion quieres?\n1.- Padre->Hijo\n2.- Hijo->Padre\n");
scanf("%d", &opcion);

//inicializo todo el buffer a vacio para que no aparezcan errores al mostrarlo
while (i<80){
		buffer[i]=' ';;
		i++;		
		}

//Padre -> Hijo
if(opcion == 1){
	printf("¿Que mensaje le quieres mandar al hijo?\n");
        setbuf(stdin,NULL);//limpio buffer
	fgets(mensaje, 80, stdin);
	
	mensaje[strlen(mensaje)-1] = '\0';
	
	

	pipe(fd);
	pid=fork();

	switch(pid){
	case-1:
		printf("No se ha podido crear hijo...");
		exit(-1);
	case 0:
		close (fd[1]);
		read (fd[0], buffer, strlen(mensaje));
		printf ("\El hijo recibe algo del pipe \"%s\"\n", buffer);
		break;
	default:
		close (fd[0]);
		write (fd[1], mensaje, strlen(mensaje));
		printf("\El padre envia mensaje al hijo \"%s\"\n", mensaje);
		wait(NULL);
		break;
	}
}

//Hijo -> Padre 
if(opcion == 2){
	printf("¿Que mensaje le quieres mandar al Padre?\n");
	 setbuf(stdin,NULL);//limpio buffer
	fgets(mensaje, 80, stdin);

	mensaje[strlen(mensaje)-1] = '\0';

	pipe(fd);
	pid=fork();

	switch(pid){
	case-1:
		printf("No se ha podido crear hijo...");
		exit(-1);
	case 0:
		close (fd[0]);
		write (fd[1], mensaje, strlen(mensaje));
		printf ("\El hijo envia mensaje al padre \"%s\"\n", mensaje);
		wait(NULL);
		break;
	default:
		close (fd[1]);
		read (fd[0], buffer,  strlen(mensaje));
		printf("\El padre recibe mensaje \"%s\"\n", buffer);
		break;
	}
}
return 0;
}
