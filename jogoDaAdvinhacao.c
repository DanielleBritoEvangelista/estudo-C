#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Imprime o cabeçalho do jogo
    printf("\n          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n          Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhacao!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");

    // Obtém o tempo atual em segundos para usar como semente para o gerador de números aleatórios
    int segundos = time(0);
    srand(segundos);

    // Gera um número aleatório grande e calcula o número secreto como o resto da divisão desse número por 100
    int numeroGrande = rand();
    int numeroSecreto = numeroGrande % 100; // O número secreto está no intervalo de 0 a 99

    int chute;              // Define a variável chute
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

    // Loop principal do jogo
    for (int i = 1; i <= numeroDeTentativas; i++) {
        printf("Tentativa %d\n", tentativas + 1); // Imprime a mensagem
        printf("Qual o seu chute? \n"); // Imprime a mensagem
        scanf("%d", &chute); // Lê o chute do usuário

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

    // Verifica se o jogador acertou ou perdeu e exibe a mensagem correspondente
    if (acertou) {
        printf("Parabens! Voce acertou!\n");
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.2f \n", pontos);
    }
    else {
        printf("Voce perdeu! Tente de novo!\n");
    }

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
