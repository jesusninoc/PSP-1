#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
pid_t pid1, pid2, pid3;
int status1, status2,status3;
int carne=0;
pid1=fork();

if ( pid1== 0 )
    {
    printf("Soy la salsa (%d, hijo de %d)\n",    getpid(), getppid());
    carne++;
    pid2=fork();
        if (pid2==0){
                //soy el hijo
                printf("Soy la carne picada (%d, hijo de %d)\n", getpid(), getppid());
		carne++;
        }
}
else{
        //waitpid(pid2, &status1, 0);
        //waitpid(pid1, &status2, 0);
	pid3=fork();
	if( pid3  == 0){
		carne = 3;
        	printf("Soy la carne (%d, hijo de %d)\n",    getpid(), getppid());
                printf("Soy la tapa (%d, hijo de %d)\n", getpid(),getppid());
	}else{

	}
}

//	if(carne==3){
//        	printf("Soy la tapa (%d, hijo de %d)\n", getpid(),getppid());
//         }
return 0;
}

