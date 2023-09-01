#include <stdio.h>

int main ()
{
    //imprime o cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de advinhacao! *\n");
    printf("******************************************\n");


    int numeroSecreto = 42;

    int chute;

    for (int i=1; i<=3; i++)
    {
        printf("Qual o seu chute? \n");
        scanf("%d", &chute);

        int acertou = chute == numeroSecreto;


        if (acertou) 
        {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador\n");

            break;
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
}