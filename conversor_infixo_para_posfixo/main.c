#include <stdio.h>

char resultado[50];
int indexResultado = 0;
char tabelaDeSimbolos[20];
int indexTabela = 0;

void procurarParenteses(char infixo[]);
void ordenarTabelaDeSimbolos();
void converter(char infixo[]);

int main(void)
{
    char infixo[100];

    printf("Digite a expressão (Obs: nao coloque espaço):\n> ");
    fgets(infixo, 100, stdin);

    converter(infixo);

    printf("%s\n", resultado);

    return 0;
}

void procurarParenteses(char infixo[])
{
    int i = 0;

    while(1)
    {
        if (infixo[i] == '(')
        {
            ++i;

            while (infixo[i] != ')')
            {
                if (infixo[i] == '*' || infixo[i] == '/' || infixo[i] == '+' || infixo[i] == '-' || infixo[i] == '^')
                {
                    tabelaDeSimbolos[indexTabela] = infixo[i];

                    ++i;
                    ++indexTabela;
                }

                resultado[indexResultado] = infixo[i];

                ++i;
                ++indexResultado;
            }

            ordenarTabelaDeSimbolos();
            
            for (int k = 0; k < indexTabela; ++k)
            {
                resultado[indexResultado] = tabelaDeSimbolos[k];

                ++indexResultado;
            }

            indexTabela = 0;
        }

        if (infixo[i] == '\0')
        {
            break;
        }

        ++i;
    }
}

void ordenarTabelaDeSimbolos()
{
    for (int l = 0; l < 2; ++l)
    {
        for (int i = 0; i < indexTabela; ++i)
        {
            if (tabelaDeSimbolos[i] == '+' || tabelaDeSimbolos[i] == '-')
            {
                for (int j = i + 1; j < indexTabela; ++j)
                {
                    char simTemp;
                    if (tabelaDeSimbolos[j] == '*' || tabelaDeSimbolos[j] == '/' || tabelaDeSimbolos[j] == '^')
                    {
                        simTemp = tabelaDeSimbolos[i];
                        tabelaDeSimbolos[i] = tabelaDeSimbolos[j];
                        tabelaDeSimbolos[j] = simTemp;
                        break;
                    }
                }
            }

            if (tabelaDeSimbolos[i] == '*' || tabelaDeSimbolos[i] == '/')
            {
                for (int k = i + 1; k < indexTabela; ++k)
                {
                    char simTemp;
                    if (tabelaDeSimbolos[k] == '^')
                    {
                        simTemp = tabelaDeSimbolos[i];
                        tabelaDeSimbolos[i] = tabelaDeSimbolos[k];
                        tabelaDeSimbolos[k] = simTemp;
                        break;
                    }
                }
            }
        }
    }
    
}

void converter(char infixo[])
{
    int i = 0;
    procurarParenteses(infixo);

    while (1)
    {
        if (infixo[i] == '(')
        {
            while (infixo[i] != ')')
            {
                ++i;
            }

            ++i;
        }

        if (infixo[i] == '*' || infixo[i] == '/' || infixo[i] == '+' || infixo[i] == '-' || infixo[i] == '^')
        {
            tabelaDeSimbolos[indexTabela] = infixo[i];

            ++i;
            ++indexTabela;
            continue;
        }

        resultado[indexResultado] = infixo[i];

        if (infixo[i] == '\0')
        {
            break;
        }

        ++i;
        ++indexResultado;
    }

    ordenarTabelaDeSimbolos();
    
    for (int k = 0; k < indexTabela; ++k)
    {
        resultado[indexResultado - 1] = tabelaDeSimbolos[k];
        
        ++indexResultado;
    }

}