#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void criptografia(char frase[], char frase2[]);
void descriptografia(char frase[], int senha);
void limparBuffer(char frase[]);

int senha;

int main(void)
{
    char frase[50];
    char frase_criptografada[50];
    int escolha;
    FILE *file = fopen("senha.txt", "a");

    while (escolha != 9)
    {
        printf("Digite uma escolha(1 para criptografar, 2 para descriptografar ou 9 para sair)\n> ");
        scanf("%i", &escolha);
        getchar(); // Ele vai pegar a quebra de linha '\n', assim evitando bugs

        if (escolha == 1)
        {
            printf("Digite a frase\n> ");

            fgets(frase, 50, stdin);
            limparBuffer(frase);
                    
            criptografia(frase, frase_criptografada);
            fprintf(file, "A senha: { %i } ", senha);
            fclose(file);

            printf("~ %s", frase_criptografada);
        }
        else if (escolha == 2)
        {
        int chave;

            printf("Digite a palavra ser descriptografada:\n> ");
            fgets(frase, 50, stdin);
            limparBuffer(frase);

            printf("Digite a senha:\n> ");
            scanf("%i", &chave);

            descriptografia(frase, chave); 
        }
    }
    
    return 0;
}

void limparBuffer(char frase[])
{
    int i = 0;
    while (frase[i] != '\n')
    {
        if (frase[i] == '\n')
        {
            frase[i] = '\0';
        }

        ++i;
    }
}

void criptografia(char frase[], char frase2[])
{
    int i = 0;
    int letra;
    int chave;
    srand(time(NULL));

    do
    {
        chave = rand() % 10;
    }
    while (chave <= 0);
    
    senha = chave;

   while (frase[i] != '\0')
   {
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            letra = frase[i] + chave;
            if (letra > 122)
            {
                letra = letra  - 26;
            }
            frase2[i] = (char)letra;
        }
        else if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            letra = (char)(frase[i] + chave);
            if (letra > 90)
            {
                letra = letra  - 26;
            }
            frase2[i] = (char)letra;
        }
        else
        {
            frase2[i] = frase[i];
        }

        ++i;
   }

   frase2[i] = '\0';
}

void descriptografia(char frase[], int senha)
{
    char frase_descriptografada[50];
    int letra;

    int i = 0;
    while (frase[i] != '\0')
    {
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            letra = frase[i] - senha;
            if (letra < 97)
            {
                letra = letra + 26;
            }
            frase_descriptografada[i] = (char)letra;
        }
        else if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            letra = frase[i] - senha;
            if (letra < 65)
            {
                letra = letra + 26;
            }
            frase_descriptografada[i] = (char)letra;
        }
        else
        {
            frase_descriptografada[i] = frase[i];
        }

        ++i;
    }

    frase_descriptografada[i] = '\0';

    printf("~  %s", frase_descriptografada);
}