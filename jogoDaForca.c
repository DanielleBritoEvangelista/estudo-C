#include <stdio.h>
#include <string.h>

//variaveis globais
char palavraSecreta[20];
char chutes[26];
int tentativas = 0;

void abertura () {
    printf("***********************\n");
    printf("**** Jogo da Forca ****\n");
    printf("***********************\n\n");
}

void chuta () {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[(tentativas)] = chute;
    (tentativas)++;

}

int jaChutou (char letra) {
    int achou = 0;

    for (int j = 0; j < tentativas; j++) {

        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca () {
    for (int i =0; i < strlen(palavraSecreta); i++) {
        
        //aqui estava o codigo 
        int achou = jaChutou(palavraSecreta[i]);    

        if(achou) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhePalavra () {
    sprintf(palavraSecreta, "MELANCIA"); 
}

int enforcou () {

    int erros =0;

    for (int i = 0; i < tentativas; i++) {

        int existe = 0;

        for (int j = 0; j < strlen(palavraSecreta); j++) {
            if (chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            } 
        }
        if (!existe) erros++;
    }

    return erros >= 5;
}

int main () {
    int acertou = 0;

    escolhePalavra();
    abertura();

    do {

        desenhaForca();
        chuta();

    } while (!acertou && !enforcou());
}