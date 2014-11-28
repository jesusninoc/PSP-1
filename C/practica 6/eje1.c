#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
pid_t pid;
int status1;
if ( (pid=fork()) == 0 )
    { /* hijo */
		//for(int i = 0; i < 10; ++i)
		//{
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		printf("Soy el hijo \n");
		//}
    }
else
    { /* padre */
		waitpid(pid, &status1, 0);
		printf("Mi proceso hijo ya ha terminado \n"); 
		//for(int i = 0; i < 10; ++i)
		//{
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		printf("Soy el padre \n");
		//}
    }
return 0;
}
