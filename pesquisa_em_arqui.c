#include <stdio.h>

int substituir_nulo(char texto[]);
_Bool verificador_de_textos(char texto[], char texto2[]);

int main(void)
{
    FILE *procurarInformacao = fopen("teste.txt", "r");

    if (procurarInformacao == NULL)
    {
        printf("O arquivo nao existe");
        return 1;
    }

    char texto[1000];
    char procura[] = "commodi consequatur. Quis aute iure reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.";

    int linhas = 0;
    while (fgets(texto, 1000, procurarInformacao) != NULL)
    {
        ++linhas;
        substituir_nulo(texto);
        
        if (verificador_de_textos(texto, procura) == 0)
        {
            printf("Frase encontrada!!! Ela esta na linha < %i >\n\n" // Tecnica para usar printf em mais de 1 linha
                   "~ %s ~\n\n", linhas, texto);
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

_Bool verificador_de_textos(char texto[], char texto2[]) // Verifica a frase para retornar se é verdadeira ou não
{
    int i = 0;
    while (texto[i] != '\0' && texto2[i] != '\0')
    {
        if (texto[i] != texto2[i])
        {
            return 1;
        }

        ++i;
    }

    return 0;

}