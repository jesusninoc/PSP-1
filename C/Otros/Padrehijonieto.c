#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
pid_t pid1, pid2;
int status1, status2;

    if ( (pid1=fork()) == 0 ){ /* hijo */
    	if ( (pid2=fork()) == 0 ){
    	   printf("Soy el 1 nieto (%d, hijo de %d)\n", getpid(),getppid());
    	}else{ /* nieto */
            waitpid(pid2, &status2, 0);
            printf("Soy el 2 hijo (%d, hijo de %d)\n", getpid(),getppid());
        }
    }else{ /* padre */
    	waitpid(pid2, &status2, 0);
        waitpid(pid1, &status1, 0);
        printf("Soy el 3 padre (%d, hijo de %d)\n", getpid(),getppid());
    }
return 0;
}
