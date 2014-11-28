#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

pid_t pid;
int i, status;

for(i=0;i<2;i++){
	pid=fork();
	if(pid){		
		wait(status);
	}else{
		printf("Soy el hijo %d (%d, hijo de %d)\n",    (i+1),getpid(), getppid());
		if(i==1){
			pid=fork();
			if (pid){
				wait(status);
			}else{
				printf("Soy el hijo 3 (%d, hijo de %d)\n",    getpid(), getppid());
				exit(0);
			}
		}
		exit(0);
	}
}

return 0;	
}
