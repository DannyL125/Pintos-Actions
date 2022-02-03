#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include<stdbool.h>


int numero;
int numCopia;



int primos(int numero,int proceso){
int Num=0;
numCopia=numero;
 while(numero>0){
        Num++;
        int CompModulo=1;
        int cont=0;
        while(CompModulo<=Num){
            if((Num%CompModulo)==0){
                cont++;
            }
               CompModulo++;
        }
        if(cont==2){
             printf("PID %d Process : El numero %d es Primo. \n" ,proceso,Num);
             numero--;  
        }
    
}
  numero=numCopia;
}

int main ( int argc , char * argv []) {
	printf("### Laboratorio 1 (Process) ###\n"); 
	printf("Ingrese Numero de Primos: ");
    if(scanf("%d", &numero)){ 
        printf("Calculado . . .\n");
        pid_t pid1;
        pid1 = fork (); 
	    printf("Iniciando procesos\n");
        if ( pid1 == -1) {
		printf ("# Creation of a child process was unsuccessful.\n");
		return -1;
	} else {
		if( pid1 > 0){
			primos(numero,getpid());
		} else {
			primos(numero,getpid());
		}
	} 

    }else{
    	printf("Ingrese un numero entero \n");
		printf("\n");
	}
    printf("FIN de Proceso.\n");
}

