#include <stdio.h>

#define TAXA_DE_AUMENTO 10
#define TAXA_DE_DIMINUICAO 10

float verificador_de_fase(int fase[]);
float horario_de_acordar(int horario_a_deitar, float tempo_de_sono);

int main(void)
{
    int horario_a_deitar, tempo_medio_fases[4];

    printf("Que horario vai deitar? ");
    scanf("%i", &horario_a_deitar);

    printf("Digite o tempo medio de cada fase de sono em minutos:\n");
    for (int i = 0; i < 4; i++)
    {
        if(i > 2)
        {
            printf("REM: ");
            scanf("%i", &tempo_medio_fases[i]);

            continue;
        }

        printf("NREM %i: ", i + 1);
        scanf("%i", &tempo_medio_fases[i]);
    }

    float tempo_de_sono = verificador_de_fase(tempo_medio_fases);

    float despertador = horario_de_acordar(horario_a_deitar, tempo_de_sono);

    printf("Você precisa dormir %.2f Horas. Então o despertador deve ser %.2f", tempo_de_sono, despertador);

    return 0;
}

float verificador_de_fase(int fase[])
{
    int fases = 0;
    float tempo_total = 0;

    while(fases != 6)
    {
        if (fases == 0)
        {
            for(int i = 0; i < 4; i++)
            {
                tempo_total += fase[i];
            }

            ++fases;
            continue;
        }

        fase[1] += (fase[1] * TAXA_DE_AUMENTO) / 100;
        fase[2] -= (fase[2] * TAXA_DE_DIMINUICAO) / 100;
        fase[3] += (fase[3] * TAXA_DE_AUMENTO) / 100;

        for(int i = 0; i < 4; i++)
        {
            tempo_total += fase[i];
        }

        ++fases;
    }

    float descontar_sono = fase[2] + fase[3];

    return (tempo_total - descontar_sono) / 60.0;
}

float horario_de_acordar(int horario_a_deitar, float tempo_de_sono)
{
    float horario = (horario_a_deitar * 1.0) + tempo_de_sono;

    if (horario > 23)
    {
        horario -= 24;
    }

    return horario;
}