#include <stdio.h>
#include <stdlib.h>

typedef struct st_reg {
    int linha, coluna, valor;
    struct st_reg *prox;
} registro;

typedef struct pilhaTCD
{
    registro * p;
    registro * q;
    int tam;
} PILHA;



int ** alocaMatriz(int n){

    int **M;
    int i;

    M = (int **)malloc(sizeof(int *)*n);

    for(i = 0; i < n; i++){
        M[i] = (int *)malloc(sizeof(int)*n);
    }

    return M;
}

int **leMatriz(char * nome, int *N){

    FILE *arq;
    int n, i, j;
    int **M;
    arq = fopen(nome, "r");
    if(arq == NULL){
        printf("tem nao\n");
        exit(1);
    }
    fscanf(arq, "%d ", &n);
    //printf("%d\n", n);

    *N = n;

    M = alocaMatriz(n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            fscanf(arq, "%d", &M[i][j]);
        }
    }
    fclose(arq);

    return M;

}

registro * criaRegistro(int lin, int col, int val){

    registro * R = (registro*)malloc(sizeof(registro));
    R->linha = lin;
    R->coluna = col;
    R->valor = val;
    R->prox = NULL;
    return R;

}

PILHA * criaPilha(){

    PILHA * P = (PILHA*)malloc(sizeof(PILHA));

    P->p = criaRegistro(0, 0, -1);
    P->q = criaRegistro(0, 0, -1);
    P->tam = 0;

    P->p->prox = P->q;
    P->q->prox = NULL;

    return P;
}

void empilha(registro * R, PILHA * P){
    
    if(P->tam == 0){
        
        P->q = R;
        P->tam++;
        //free(R);
        return;

    }
    
    R->prox = P->q;
    P->q = R;

    P->tam++;

    return;
}

registro * desempilha(PILHA * P){

    if(P->tam == 0){
        return NULL;
    }

    registro * aux;

    aux = P->q;
    P->q = P->q->prox;
    P->tam--;

    return aux;

}

void destroiPilha(PILHA * P){
    
    registro * aux;
    while(P->tam > 0){
        aux = desempilha(P);
        free(aux);
    }
    free(P->p);
    free(P->q);
    free(P);
}


registro * encontraValor(int **M, int N){

    int i, j, k;
    k = -1;
    registro * R = criaRegistro(0, 0, -1);

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(M[i][j] > k){

                k = M[i][j];
                
                R->coluna = j;
                R->linha = i;
                R->valor = k;
                R->prox = NULL;

            }
        }
    }

    return R;

}

int ehVizinho(int lin, int col, registro * R, int N){

    

    if ((R->linha + lin < N) && (R->coluna + col <N) &&
    (R->linha + lin >= 0) && (R->coluna + col >= 0)){
        return 1;
    }

    return 0;

}


int cavalo(int **M, int n){

    int i, j, a, b;
    PILHA * P = criaPilha();
    registro * R = encontraValor(M, n);
    empilha(R, P);
    int achou;
    registro * aux;

    static const int plin[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
    static const int pcol[8] = { 1,  2,  2,  1, -1, -2, -2, -1}; 


    while(P->tam > 0){

        aux = desempilha(P);
        achou = 0;
        i = 0; j = 0;

        while(i < 8 && j < 8){

            if(ehVizinho(plin[i], pcol[j], aux, n) && achou == 0){
               
                a = aux->linha+plin[i];
                b = aux->coluna+pcol[j];

            
                if(M[a][b] == 0){
                    
                    empilha(criaRegistro(a, b, aux->valor+1), P);
                    
                    M[a][b] = aux->valor+1;
                    
                    achou = 1;

                }
            }
            i++; j++;

        }
        
        if(aux->valor == n*n){
            return 1;
        }

        if(achou == 0){
            M[a][b] = 0;
        }
        
    }

    return -1;
    
}

void imprimeMatriz(int **M, int N){

    int i, j;

    for (i = 0; i < N; ++i) {
       for (j = 0; j < N; ++j)
         printf("%3d ", M[i][j]);
       printf("\n");
    }
}

void liberaMatriz(int **M, int n){
  int i;
  for(i = 0; i < n; i++)
    free(M[i]);
  free(M);
}

int main(){
    

    int C;
    int N;
    int **M;
    char nome[100];
    
    scanf("%s", nome);

    M = leMatriz(nome, &N);
    C = cavalo(M, N);

    if(C > 0){
        printf("Solucao:\n");
        imprimeMatriz(M, N);
    }
    else{
        M = leMatriz(nome, &N);
        imprimeMatriz(M, N);
        
    }
    
    
    return 0;
}