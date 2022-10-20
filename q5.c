#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int InsereFila(int x, int f[], int *n, int *s){

    
    if(*s == N - 1){
        
        *s = -1;
        *n = *n - 1; 
        
    }

    *s = *s + 1;
    f[*s] = x;
    *n = *n + 1;
    
    return (*n == N);
}


int RemoveFila(int x, int f[], int * s, int * n){
    
    if(*n == 0){

        return x;

    }

    x = f[*s];
    *n = *n - 1;
    *s = *s + 1;

    return x;

}


void ImprimeFila(int f[], int * s, int *n){

    int i, j;


    for(i = *s, j = 0; j < *n; i++, j++){
        
        printf("%d\n", f[i]);
        if(i == N - 1){
            i = 0;
        }


    }
}

int main(){
    
    
    int *s; int *n;
    int tamanho = 0; int inicio = -1;
    int f[N];

    n = &tamanho; s = &inicio; 
    InsereFila(0, f, n, s);
    InsereFila(1, f, n, s);
    InsereFila(2, f, n, s);
    InsereFila(3, f, n, s);
    InsereFila(4, f, n, s);
    InsereFila(5, f, n, s);
    ImprimeFila(f, s, n);
    RemoveFila(-1, f, s, n);
    ImprimeFila(f, s, n);
    RemoveFila(-1, f, s, n);
    ImprimeFila(f, s, n);
    

    return 0;
}