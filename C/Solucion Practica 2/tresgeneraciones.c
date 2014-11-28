#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
 
int main(int argc, char *argv[]) 
{ 
pid_t pid1, pid2; 
int status1, status2; 

pid1=fork();

if(pid1==0){
	pid2=fork();
	if (pid2==0){
		printf("Soy el nieto (%d, hijo de %d)\n",    getpid(), getppid());
	}
	else{
	waitpid(NULL);
	printf("Soy el padre (%d, hijo de %d)\n",    getpid(), getppid());
	}		
}

else{
	waitpid(NULL);
	printf("Soy el abuelo (%d, hijo de %d)\n",    getpid(), getppid());
}

return 0;
}
