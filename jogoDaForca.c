#include <stdio.h>
#include <string.h>

void abertura () {
    printf("***********************\n");
    printf("**** Jogo da Forca ****\n");
    printf("***********************\n\n");
}

void chuta (char chutes[26], int* tentativas) {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;

}
int main () {
    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA"); 

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do {

        for (int i =0; i < strlen(palavraSecreta); i++) {
            
            int achou = 0;

            for (int j = 0; j < tentativas; j++) {

                if (chutes[j] == palavraSecreta[i]) {
                    achou = 1;
                    break;
                }
            }
            if(achou) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
}