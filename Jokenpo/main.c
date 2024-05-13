#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void analise_do_jogo(int escolha);

struct contador
{
    int vitoria;
    int derrota;
    int empates;
} tabela;

char simbolos[3][8] = {{"Pedra"}, {"Papel"}, {"Tesoura"}};

int main (void)
{   
    int saida;
    do
    {
        int escolha;

        do
        {
            printf("==== Bem vindo ao Jokenpo ====\n"
               "Digite 1 para \"Pedra\"\n"
               "Digite 2 para \"Papel\"\n"
               "Digite 3 para \"Tesoura\"\n> ");
            scanf("%i", &escolha);

            printf("\n");
        }
        while(escolha > 3 || escolha < 1);

        _sleep(500);

        --escolha;
        analise_do_jogo(escolha);

        _sleep(600);
        printf("\n");

        printf("=== Placar ===\n"
               " Vitorias: %i\n"
               " Derrotas: %i\n"
               " Empates: %i\n", tabela.vitoria, tabela.derrota, tabela.empates);

        printf("\nDigite [ 1 ] para sair, [ 2 ] para continuar: \n> ");
        scanf("%i", &saida);
    }
    while(saida != 1);

    return 0;
}

void analise_do_jogo(int escolha)
{
    srand(time(NULL));
    int escolha_computador = rand() % 2;
    
    printf("[ Sua escolha \"%s\" ] VS [ Escolha do computador \"%s\" ] \n", simbolos[escolha], simbolos[escolha_computador]);

    if (escolha == 0)
    {
        if (escolha_computador == 1)
        {
            printf("~ PERDEU\n");
            ++tabela.derrota;
        }
        else if (escolha_computador == 2)
        {
            printf("~ GANHOU\n");
            ++tabela.vitoria;
        }
    }
    else if (escolha == 1)
    {
        if (escolha_computador == 2)
        {
            printf("~ PERDEU\n");
            ++tabela.derrota;
        }
        else if (escolha_computador == 0)
        {
            printf("~ GANHOU\n");
            ++tabela.vitoria;
        }
    }
    else if (escolha == 2)
    {
        if (escolha_computador == 0)
        {
            printf("~ PERDEU\n");
            ++tabela.derrota;
        }
        else if (escolha_computador == 1)
        {
            printf("~ GANHOU\n");
            ++tabela.vitoria;
        }
    }

    if (escolha == escolha_computador)
    {
        printf("~ EMPATE\n");
        ++tabela.empates;
    }
      
}