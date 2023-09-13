#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
    //imprime o cabeçalho do jogo
    printf("\n          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhacao!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");

    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand(); 

    int numeroSecreto = numeroGrande % 100; //define a variável numeroSecreto como 42
    int chute;              //define a variável chute
    int tentativas = 0;
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("\nQual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas; 
    if (nivel == 1) {
        numeroDeTentativas = 20;
    } 
    else if (nivel == 2) {
        numeroDeTentativas = 15;
    }
    else {
        numeroDeTentativas = 6;
    }

    for (int i = 1; i <= numeroDeTentativas; i++) {

        printf("Tentativa %d\n", tentativas+1); //imprime a mensagem
        printf("Qual o seu chute? \n"); //imprime a mensagem
        scanf("%d", &chute); //lê o chute do usuário

        if (chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        acertou = chute == numeroSecreto;  
        int maior = chute > numeroSecreto;   

        if (acertou) {
            break;
        }
        else if (maior) {
            printf("Seu chute foi maior que o numero secreto!\n");
        }
        else {
            printf("Seu chute foi menor que o numero secreto!\n");   
        }
        tentativas++;

        double pontosPerdidos = abs((chute - numeroSecreto)) / 2.0;
        pontos = pontos - pontosPerdidos;
    }

    printf("Fim de jogo!\n");

    if (acertou)
    {
        printf("Parabens! Voce acertou!\n");
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.2f \n", pontos);

    }
    else
    {
        printf("Voce perdeu! Tente de novo!\n");
    }

}