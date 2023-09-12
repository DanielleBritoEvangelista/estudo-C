#include <stdio.h>


int main ()
{
    //imprime o cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de advinhacao! *\n");
    printf("******************************************\n");


    int numeroSecreto = 42; //define a variável numeroSecreto como 42
    int chute;              //define a variável chute
    int ganhou = 0;
    int tentativas = 0;

    while (1) {

        printf("Tentativa %d\n", tentativas+1); //imprime a mensagem
        printf("Qual o seu chute? \n"); //imprime a mensagem
        scanf("%d", &chute); //lê o chute do usuário

        if (chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        int acertou = chute == numeroSecreto;  
        int maior = chute > numeroSecreto;   

        if (acertou) {
            printf("Parabens! Voce acertou!\n");
            printf("Jogue de novo, voce esta sendo um bom jogador\n");

            break;
        }
        else if (maior) {
            printf("Seu chute foi maior que o numero secreto!\n");
        }
        else {
            printf("Seu chute foi menor que o numero secreto!\n");   
        }
        tentativas++;
    }

    printf("Fim de jogo!\n");
    printf("Voce acertou em %d tentativas!\n", tentativas);
}