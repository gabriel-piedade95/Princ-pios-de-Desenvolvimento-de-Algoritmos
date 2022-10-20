#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Lista (char *cmd){
    char fila[4]; int s = 0 , t = 0;
    char pilha[10]; int u = 0 , i = 0;
    fila[t++] = 'A'; fila[t++] =  'B'; fila[t++] = 'C'; fila[t++] =  'D';
    while (cmd[i] != '\0' && s < t ) {
        if (cmd[i] == 'e') pilha[u++] = fila[s++];
        else if (cmd[i] == 'd' && u > 0) printf("%c\n" , pilha[--u]);
        i++;
    }
}

int main(){

    char cmd[] = "eeed";

    Lista(cmd);

    return 0;
}