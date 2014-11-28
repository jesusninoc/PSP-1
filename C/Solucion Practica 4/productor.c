#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int fp;
  char mensaje[80];
//  char saludo[]="Un saludo!!!";
	
 printf("Escribe los mensajes que quieres mandar (Escribe '.' para terminar)");
  while (strcmp(mensaje, "exit")!=0){
  fgets(mensaje, 30, stdin);
  mensaje[strlen(mensaje)-1] = '\0';

  fp=open("FIFO1",1);

if (fp==-1)
	{
	printf ("ERROR AL ABRIR ARCHIVO\n");
	exit(1);
	}
printf ("mandando información al fifo...\n");
write (fp,mensaje,strlen(mensaje));
close(fp);
}
return 0;
}
