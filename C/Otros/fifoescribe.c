#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int fp;
  char saludo[]="Un saludo!!!";
	//printf("Escribe el mensaje que quires que le envie el padre al hijo\n");
	//scanf("%s",saludo);
  fp=open("FIFO1",1);

if (fp==-1)
	{
	printf ("ERROR AL ABRIR ARCHIVO\n");
	exit(1);
	}
printf ("mandando información al fifo...\n");
write (fp,saludo,strlen(saludo));
close(fp);
return 0;
}
