#include <stdio.h>

int coluna_incio = 0;
int coluna_final = 0;

int substituir_nulo(char texto[]);
void separacao_de_palavras(char string[], char palavras[][50]);
_Bool verificador_de_textos(char texto[], char texto2[]);
int contar_caracteres(char texto[]);

int main(void)
{
    FILE *procurarInformacao = fopen("teste.txt", "r");

    if (procurarInformacao == NULL)
    {
        printf("O arquivo nao existe");
        return 1;
    }

    char texto[1000];
    char procura[] = "mateus chato";
    char palavras[20][50];

    separacao_de_palavras(procura, palavras); // Nova função adicionada, precisa usar ela ainda

    int linhas = 0;
    while (fgets(texto, 1000, procurarInformacao) != NULL)
    {
        ++linhas;
        substituir_nulo(texto);
        
        if (verificador_de_textos(texto, procura) == 0)
        {
            printf("Frase encontrada!!! Ela esta na linha < %i >, coluna inicial < %i > e coluna final < %i >\n\n" // Tecnica para usar printf em mais de 1 linha
                   "~ %s ~\n\n", linhas, coluna_incio, coluna_final, texto);
            return 0;
        }
    }

    printf("Frase nao encontrada\n");
    return 1;

}

int substituir_nulo(char texto[]) // Padroniza os finais das frases pega no arquivo
{
    for (int i = 0;; ++i)
    {
        if (texto[i] == '\n')
        {
            texto[i] = '\0';
            return 0;
        }
    }
}

void separacao_de_palavras(char string[], char palavras[][50])
{

    for (int i = 0, j = 0, k = 0;; ++i, k = 0)
    {
        
        while (string[j] != '\b' && string[j] != '\0')
        {
            palavras[i][k] = string[j];

            ++j;
            ++k;
        }
        
        if (string[j] == '\b')
        {
           palavras[i][j] = '\0'; 
           ++j;
        }
        
        if (string[j] == '\0')
        {
            palavras[i + 1][0] = '\0';
            break;
        }

    }

}

_Bool verificador_de_textos(char texto[], char texto2[]) // Verifica a frase para retornar se é verdadeira ou não
{
    int i = 0;
    int k = 0;
    
    while (texto[i] != '\0')
    {

        if (texto[i] != texto2[k])
        {
            k = 0;

            ++i;
            continue;
        }
        
        ++k;

        if (contar_caracteres(texto2) == k)
        {
            coluna_incio = (i - contar_caracteres(texto2)) + 2;
            coluna_final = i + 1;
            return 0;
        } 

        ++i;
 
    }


    return 1;
}

int contar_caracteres(char texto[])
{
    int i = 0;

    while (texto[i] != '\0')
    {
        ++i;
    }

    return i;
}