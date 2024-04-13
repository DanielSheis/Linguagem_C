#include <stdio.h>
#include <String.h>

struct iventorio
{
    char nome[20];
    int quant;
} iventorioAutoPecas[10], *pdeletar_produto;

_Bool verificarString(char string1[], char string2[]);
void adcionarProdutos(void);
int imprimirProduto(char nome[]);

int main(void)
{
    int fecharPrograma;
    do
    {
        int escolha;

        printf("========= Gerenciador de iventorio =========\n");
        printf("1 - Adicionar produtos\n2 - Ver produtos\n3 - Retirar produto\n");
        scanf("%i", &escolha);

        switch (escolha)
        {
            case 1:
                adcionarProdutos();
                break;

            case 2: ;
                char nomeProduto[20];

                printf("Para ver somente um produto digite o nome dele, para ver o inventorio completo digite <ALL>:\n");
                scanf("%s", nomeProduto);

                imprimirProduto(nomeProduto);
                break;

            case 3:
                break;

            default:
                printf("Essa opcao nao existe\n");
                break;
        }

        printf("Deseja fechar o progama? digite 1, se nao digite 2\n");
        scanf("%i", &fecharPrograma);
    }
    while(fecharPrograma != 1);

    return 0;
}

_Bool verificarString(char string1[], char string2[])
{
    int i = 0;

    while (string1[i] != '\0' || string2[i] != '\0')
    {
        if (string1[i] != string2[i])
        {
            return 0;
        }

        i++;
    }

    return 1;
}

void adcionarProdutos(void)
{
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o nome do produto (deve ser nome unico):\n");
        scanf("%s", iventorioAutoPecas[i].nome);
        printf("Digite a quantidade de item:\n");
        scanf("%i", &iventorioAutoPecas[i].quant);
    }
}

int imprimirProduto(char nome[])
{
    if (verificarString(nome, "ALL") == 1)
    {
        printf("Nome    Quantidade\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%s:    %i\n", iventorioAutoPecas[i].nome, iventorioAutoPecas[i].quant);
        }

        return 1;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (verificarString(nome, iventorioAutoPecas[i].nome) == 1)
            {
                printf("*** Produto encontrado ***\n");
                printf("Nome: %s     Quantidade: %i     id: %i\n", iventorioAutoPecas[i].nome, iventorioAutoPecas[i].quant, i);
                
                int escolha;
                printf("Gostaria de procurar outro item? digite 1 para sim e 2 para nao\n");
                scanf("%i", &escolha);

                if(escolha == 1)
                {
                    char nomeProduto[20];

                    printf("Para ver somente um produto digite o nome dele, para ver o inventorio completo digite <ALL>:\n");
                    scanf("%s", nomeProduto);

                    imprimirProduto(nomeProduto);
                }
                else
                {
                    return 1; // Vai sair da função
                }
            }
        }
        printf("*** Produto nao encontrado ***\n");

        int escolha;
        printf("Gostaria de procurar outro item? digite 1 para sim e 2 para nao\n");
        scanf("%i", &escolha);

        if(escolha == 1)
        {
            char nomeProduto[20];

            printf("Para ver somente um produto digite o nome dele, para ver o inventorio completo digite <ALL>:\n");
            scanf("%s", nomeProduto);

            imprimirProduto(nomeProduto);
        }

        return 0;
    }
}
