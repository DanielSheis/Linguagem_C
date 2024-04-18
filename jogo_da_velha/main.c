#include <stdio.h>

char tabuleiro[3][3] = { {'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'} };

void marcarTabuleiro(int linha, int coluna, int jogador);
void imprimirTabuleiro();

int main(void)
{
    int linha, coluna, jogador = 1;

    do
    {
        printf("JOGADOR %i:\n", jogador);

        printf("Digite a linha: ");
        scanf("%i", &linha);

        printf("Digite a coluna: ");
        scanf("%i", &coluna);

        marcarTabuleiro(linha, coluna, jogador);

        ++jogador;
    }
    while(jogador <= 2);

    imprimirTabuleiro();

    return 0;
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

int verificarTabuleiro()
{
    
}