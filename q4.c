#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Balanceada(char s[]){

    int t = 0; int i = -1;
    while(s[++i] != '\0'){

        if(s[i] == '(') t++;

        else if(s[i] == ')' && t > 0 ) t--;

        else return 0;
    }

    if(t == 0){
        return 1;
    }
    return 0;
}

int Balanceada_Errada(char s[]){

    int t = 0; int i = -1;
    while(s[++i] != '\0'){

        if(s[i] == '(') t++;

        else if(s[i] == ')' && t > 0 ) t--;

        else return 0;
    }

    
    return 1;
}

int main(){

    char a[] = "(()))()";
    char b[] = "())(()";
    char c[] = "(()()))";
    char d[] = "((())";

    printf("Balanceada Errada:\n");
    printf("i: %d\n",Balanceada_Errada(a));
    printf("ii: %d\n",Balanceada_Errada(b));
    printf("iii: %d\n",Balanceada_Errada(c));
    printf("iv: %d\n\n",Balanceada_Errada(d));

    printf("Balanceada corrigida:\n");
    printf("i: %d\n",Balanceada(a));
    printf("ii: %d\n",Balanceada(b));
    printf("iii: %d\n",Balanceada(c));
    printf("iv: %d\n",Balanceada(d));

    return 0;
}