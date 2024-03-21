// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{

    printf("\n\n Bem vindo ao Jogo de Adivinhação! \n\n");

    // Variaveis
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;

    // Pontos Inicial
    double pontos = 1000;

    // Numero Secreto
    srand(time(0));
    int numerosecreto = rand() % 100;

    // Nivel de Dificuldade
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");

    scanf("%d", &nivel);

    switch(nivel) 
    {
        case 1: 
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
    }

    // Jogo
    for(int i = 1; i <= totaldetentativas; i++) 
    {

        printf("-> Tentativa %d de %d\n", i, totaldetentativas);

        printf("Chute um número: ");
        scanf("%d", &chute);

        // tratando chute de numero negativo
        if(chute < 0) {
            printf("Você não pode chutar números negativos\n");
            i--;
            continue;
        }

        // verifica se acertou, foi maior ou menor
        acertou = chute == numerosecreto;

        if(acertou) 
        {
            break;
        } 
        else if(chute > numerosecreto) 
        {
            printf("\nSeu chute foi maior do que o número secreto!\n\n");
        } 
        else 
        {
            printf("\nSeu chute foi menor do que o número secreto!\n\n");
        }

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }

    printf("\n");
    if(acertou) 
    {
        printf("\nParabéns! Você acertou!\n");
        printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
    } 
    else 
    {
        printf("\nVocê perdeu! Tente novamente!\n\n");
    }


}