#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

pid_t pid;
int i,status;

for(i=0;i<3;i++){
	pid=fork();
	if(pid){
		wait(status);		
	}else{
		printf("Soy el hijo %d (%d, mi padre es %d)\n",    (i+1),getpid(), getppid());
		exit(0);
	}
}

return 0;	
}
