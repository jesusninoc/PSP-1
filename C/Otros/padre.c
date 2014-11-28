#include <stdio.h>
#include <unistd.h>
void main(){
pid_t id_pactual,id_padre;
id_pactual=getpid(); //devuelve id proceso actual
id_padre=getppid(); //devuelve id padre
printf ("PID de este proceso %d\n", id_pactual);
printf ("PID de su padre %d\n", id_padre);
}
