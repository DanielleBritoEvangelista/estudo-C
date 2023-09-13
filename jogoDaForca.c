#include <stdio.h>
#include <string.h>
int main () {
    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA"); 

    int acertou = 0;
    int enforcou = 0;

    do {
        char chute;
        scanf("%c", &chute);


        for (int i = 0; i < strlen(palavraSecreta); i++) {
            printf("Estou vendo a letra %c na posição %d\n", palavraSecreta[i], i);
            if (palavraSecreta[i] == chute) {
                printf("A posição %d tem essa letra\n", i);
            }
        }
    } while (!acertou && !enforcou);
}