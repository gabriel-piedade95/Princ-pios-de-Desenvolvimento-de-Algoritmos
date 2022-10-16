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

        P->q->valor = R->valor;
        P->q->coluna = R->coluna;
        P->q->linha = R->linha;
        P->tam++;
        free(R);
        return;

    }

    R->prox = P->q;
    P->q = R;

    P->tam++;

    return;
}

registro * desempilha(PILHA * P){

    registro * aux;

    aux = P->q;
    P->q = P->q->prox;
    P->tam--;

    return aux;

}

void destroiPilha(PILHA * p){
    
    registro * aux;
    while(p->tam > 0){
        aux = desempilha(p);
        free(aux);
    }
    free(p);
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

//NÃO TESTEI ESSA AINDA!!
int ehVizinho(int lin, int col, int **M, registro * R){

    

    if (((abs(lin - R->linha) == 2) & (abs(col - R->coluna) == 1)) == 1 || ((abs(lin - R->linha) == 1) & (abs(col - R->coluna) == 2)) == 1){
        return 1;
    }

    return 0;

}

//AINDA NÃo ESTA PRONTA!!
int cavalo(int **M, int n){

    int i, j;
    int x = -1;
    PILHA * P = criaPilha();
    registro * R = encontraValor(M, n);
    empilha(R, P);
    int n_vizinhos;
    registro * aux;
    while(P->tam > 0){

        aux = desempilha(P);

        n_vizinhos = 0;

        if(aux->valor == n*n){
            x = 1;
            break;
        }

        
        else{
                for(i = 0; i < n; i++){
                    for(j = 0; j < n; j++){
                        if(ehVizinho(i, j, M, aux)){
                            if(M[i][j] == 0){
                                empilha(aux, P);
                                n_vizinhos++;
                            }
                            
                        }
                    }
                }
            }
        
        if(n_vizinhos == 0){
            M[aux->linha][aux->coluna] = 0;
        }
    }

    free(aux);
    destroiPilha(P);
    return x;
    
}

void liberaMatriz(int **M, int n){
  int i;
  for(i = 0; i < n; i++)
    free(M[i]);
  free(M);
}

int main(){
    
    int **M;
    int N;
    int C;
    
    M = leMatriz("tabuleiro52.txt", &N);
    //C = cavalo(M, N);
    liberaMatriz(M, N);
    printf("%d\n", C);


    return 0;
}
