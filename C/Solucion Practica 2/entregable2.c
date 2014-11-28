#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
 
int var = 6;

int main(int argc, char *argv[]){
pid_t pid1;

	if((pid1=fork())==0){
		var=var+5;
		printf("Soy el hijo. Valor variable = %d\n", var);
	}
	else {
		
		var=var-5;
		printf("Soy el padre. Valor variable = %d\n", var);
	}

}

/*Cada proceso tendra su propia variable independiente por lo tanto el proceso hijo sumara 6+5=11
y el proceso padre restara 6-5=11*/
