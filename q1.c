#include <stdio.h>
#include <stdlib.h>

int main(){

    char s [] = "MAC122";
    char *p = s;
    printf("%s\n" , p + p[1] - p[0]);

    return 0;
}