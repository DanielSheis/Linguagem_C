#include <stdio.h>

#define LIMITE_STRING 100 // Limite de caractere permitido

int linha_parada = 0;

_Bool comparacaoString(char string_input[], char string_arqui[]);
void limparBuffer(char string[]);
void padronizarString(char string[]);
void imprimirResposta(char string[]);
_Bool adicionarPalavra(FILE *file);

int main(void)
{
    char input[LIMITE_STRING];
    char inputArqui[LIMITE_STRING];
    int escolha;
    FILE *file = fopen("info.txt", "r+");
 
    do
    {
        printf("================================================\n");
        printf("Adcionar palavra: 1\nProcurar palavra: 2\nSair: 3\n");
        printf("================================================\n> ");
        scanf("%i", &escolha);
        fflush(stdin);
        printf("\n");

        if (escolha == 1)
        {
            adicionarPalavra(file);
            return 0;
        }
        else if (escolha == 2)
        {
            printf("Digite a palavra:\n> ");
            fgets(input, LIMITE_STRING, stdin);

            limparBuffer(input); // Limpa o buffer tirando '\n' e substituindo por '\0'
            padronizarString(input); // Transforma qualquer frase em minusculo

            while ((fgets(inputArqui, LIMITE_STRING, file)) != NULL)
            {
                limparBuffer(inputArqui);
                padronizarString(inputArqui);

                if (comparacaoString(input, inputArqui) == 1)
                {
                    printf("================================================\n~ ");
                    imprimirResposta(inputArqui);
                    printf(" ~\n================================================\n");
                    fclose(file);
                    return 0;
                }
            }

            printf("Palavra-chave nao encontrada\n");
            return 1;

        }
    }
    while(escolha != 3);
   
    return 0;
}

_Bool comparacaoString(char string_input[], char string_arqui[])
{
    int i = 0;

    while (string_input[i] != '\0')
    {
        if (string_input[i] != string_arqui[i])
        {
            return 0;
        }

        ++i;
    }

    if (string_input[i] == '\0' && string_arqui[i] == ':')
    {
        linha_parada = i; // A linha de parada recebe o valor para poder dar a resposta corretamente
        return 1;
    }

    return 0;
}

void limparBuffer(char string[])
{
    int i = 0;
    while (1)
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
        ++i;
    }
}

void padronizarString(char string[])
{
    int i = 0;

    while (string[i] != '\0' && string[i] != ':')
    {
        if (string[i] >= 65 && string[i] <= 90) // 65(A) e 90(Z) e o valor ASCII das letras maiuscula
        {
            string[i] = string[i] + 32; // 32 é somado ao valor original, assim ele vira minusculo ex: 97(a)
        }

        ++i;
    }
}

void imprimirResposta(char string[])
{
    int i = 0;
    int posicao = linha_parada + 3; // posição é o valor de onde começa a resposta, que é sempre o tamanho da palavra-chave + 3

    while (string[posicao + i] != '"')
    {
        printf("%c", string[posicao + i]);
        ++i;
    }
}

_Bool adicionarPalavra(FILE *file)
{
    char inputArqui[LIMITE_STRING];
    char palavraChave[LIMITE_STRING];
    char significado[LIMITE_STRING];

    printf("- Digite a palavra-chave: ");
    fgets(palavraChave, LIMITE_STRING, stdin);
    limparBuffer(palavraChave);
    padronizarString(inputArqui);

    printf("- Digite o siginificado dela (limite %i caracteres): ", LIMITE_STRING - 1);
    fgets(significado, LIMITE_STRING, stdin);
    limparBuffer(significado);
    

    while (1)
    {

        if ((fgets(inputArqui, LIMITE_STRING, file)) == NULL)
        {
            fprintf(file, "%s: \"%s\"\n", palavraChave, significado);
            fclose(file);
            printf("================================================\n");
            printf("~ Palavra salva com sucesso!!! ~\n");
            printf("================================================\n");
            return 0;
        }

        limparBuffer(inputArqui);
        padronizarString(inputArqui);

        if (comparacaoString(palavraChave, inputArqui) == 1)
        {
            printf("A palavra ja existe\n");
            fclose(file);
            return 1;
        }

    }
}