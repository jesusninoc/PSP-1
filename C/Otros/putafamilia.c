#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    pid_t pid1;
    int status1;
    int numero=6;

    if ( (pid1=fork()) == 0 ){ /* hijo */
        numero +=5;
        printf("Soy el hijo Valor variable %d \n",numero);
    }else{ /* padre */
        numero -=5;
        printf("Soy el padre Valor variable %d \n",numero);
    }
    return 0;
}
