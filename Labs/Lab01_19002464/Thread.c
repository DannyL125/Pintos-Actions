#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include<stdbool.h>


int numero;
int numCopia;

void *myThread(void *vargp) {
	int *myid = (int *)vargp; 
	
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
             printf("THREAD %d: El numero %d es Primo. \n" ,*myid,Num);
             numero--;  
        }
    
}
    numero=numCopia;
} 


//agregamos la entrada del numero 

int main ( int argc , char * argv []) {
    //declaracion de threads
    pthread_t thread1;
    pthread_t thread2;
	printf("### Laboratorio 1 (Threads) ###\n"); 
	printf("Ingrese Numero de Primos: ");
    if(scanf("%d", &numero)){ 
        printf("Calculado . . .\n");
        pthread_create(&thread1,NULL,myThread,(void *)&thread1); 
        pthread_create(&thread2,NULL,myThread,(void *)&thread2);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }else{
        printf("Ingrese un numero entero \n");
	//free(numero);
	printf("\n"); }
    printf("FIN.\n");
}






    
