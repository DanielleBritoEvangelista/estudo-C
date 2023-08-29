#include <stdio.h>

int main ()
{
    //imprime o cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de advinhacao! *\n");
    printf("******************************************\n");


    int numeroSecreto = 42;


    int chute;

    int acertou = chute == numeroSecreto;

    printf("Qual o seu chute? \n");
    scanf("%d", &chute);

    if (acertou) 
    {
        printf("Parabéns! Você acertou!\n");
        printf("Jogue de novo, você é um bom jogador\n");
    }
    else 
    {
        int maior = chute > numeroSecreto;
        
        if (maior) 
        {
            printf("Seu chute foi maior que o número secreto!\n");
        }
        else
        {
            printf("Seu chute foi menor que o número secreto!\n");
        }
    }
}