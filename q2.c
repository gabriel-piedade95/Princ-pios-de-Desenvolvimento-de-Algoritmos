#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Filtro(char * s, char t){

    char p[50];
    int i, j;
    
    j = 0;
    for(i = 0; s[i] != '\0'; i++){

        
        if(s[i] != t){
            p[j] = s[i];
            j++;
        }
    }
    j++;
    p[j] = '\0';

    for(i = 0; i < j; i++){
        s[i] = p[i];
    }

    //printf("%s\n", s);


}

int main(){

    char s[] = "MAC";
    char t = 'A';

    printf("%s\n", s);
    Filtro(s, t);
    
    printf("%s\n", s);

    //free(s);

    return 0;
}