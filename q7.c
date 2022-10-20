#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fatorialPilha(int n){

    int Pilha[n];

    int topo = 0;

    Pilha[topo] = n;
    topo++;
    n--;
    

    while(topo != 0){

        if(n == 1){

            topo--;
            Pilha[topo-1] = Pilha[tam] * Pilha[tam-1];
            printf("%d\n", Pilha[tam-1]);
            
            

        }

        else { 
            
            Pilha[topo] = n;
            topo++;
            printf("%d\n", Pilha[topo]);
            n--;
            
        }
    }

    return Pilha[0];

}

int main(){

    int n = 5;
    
    printf("%d! = %d\n", n, fatorialPilha(n));
    return 0;
}