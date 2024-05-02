#include <stdio.h>

char tabuleiro[3][3] = { {'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'} };

void marcarTabuleiro(int linha, int coluna, int jogador);
void imprimirTabuleiro();
int verificarTabuleiro(int jogador);
_Bool espacoVazio();

int main(void)
{
    printf("=============================\n");
    printf("        Jogo da velha\n");
    printf("=============================\n");

    while (1)
    {
        int linha, coluna, jogador = 1;

        do
        {
            printf("JOGADOR %i:\n", jogador);

            printf("Digite a linha: ");
            scanf("%i", &linha);

            printf("Digite a coluna: ");
            scanf("%i", &coluna);

            --linha;
            --coluna;

            marcarTabuleiro(linha, coluna, jogador);
            imprimirTabuleiro();

            if (verificarTabuleiro(jogador))
            {
                return 0;
            }

            if (espacoVazio() == 1)
            {
                printf("Jogo empatado\n");
                return 1;
            }

            ++jogador;
        }
        while(jogador <= 2);
    }
}

void marcarTabuleiro(int linha, int coluna, int jogador)
{
    int i = 0;

    while (i < 3)
    {
        int k = 0;

        while (k < 3)
        {
            if (i == linha && k == coluna)
            {
                if (tabuleiro[i][k] == '-')
                {
                    if (jogador == 1)
                    {
                        tabuleiro[i][k] = 'X';
                        break;
                    }
                    else
                    {
                        tabuleiro[i][k] = 'O';
                        break;
                    }
                    
                }

                printf("Jogador %i, essa linha ja esta marcada\n", jogador);
                break;
            }

            ++k;
        }

        ++i;
    }
}

void imprimirTabuleiro()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            printf("%c ", tabuleiro[i][k]);
        }

        printf("\n");
    }
}

int verificarTabuleiro(int jogador)
{
    char resultadoFlutuante;
    int resultado = 0;

    if (jogador == 1)
    {
        resultadoFlutuante = 'X';
    }
    else
    {
        resultadoFlutuante = '0';
    }

    for (int i = 0; i < 3; i++)
    {

        // Confere as linhas horizontal
        if (tabuleiro[i][0] == resultadoFlutuante && tabuleiro[i][1] == resultadoFlutuante && tabuleiro[i][2] == resultadoFlutuante)
        {
            printf("Jogador %c ganhou\n", resultadoFlutuante);
            return 1;
        }

        // Confere as linhas transversais da esquerda para direita
        if (tabuleiro[0][0] == resultadoFlutuante && tabuleiro[1][1] == resultadoFlutuante && tabuleiro[2][2] == resultadoFlutuante)
        {
            printf("Jogador %c ganhou\n", resultadoFlutuante);
            return 1;
        }

        // Confere as linhas transversais da direita para esquerda
        if (tabuleiro[0][2] == resultadoFlutuante && tabuleiro[1][1] == resultadoFlutuante && tabuleiro[2][0] == resultadoFlutuante)
        {
            printf("Jogador %c ganhou\n", resultadoFlutuante);
            return 1;
        }

        // confere as linhas verticais
        for (int k = 0; k < 3; k++)
        {
            if (tabuleiro[k][i] == resultadoFlutuante)
            {
                ++resultado;
            }

            if (resultado == 3)
            {
                printf("Jogador %c ganhou\n", resultadoFlutuante);
                return 1;
            }
        }

        resultado = 0;  
    }

    return 0;
}

_Bool espacoVazio()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (tabuleiro[i][k] == '-')
            {
                return 0;
            }
        }
    }

    return 1;
}