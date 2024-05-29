# Infixo e Posfixo

|Infixo|Posfixo|
|-------|-------|
| A + B |  AB+  |
| A + B * C| ABC*+|
| (A + B) / (C - D) | AB+CD-/ |
| (A - B) / (C + D) * E | AB-CD+/E* |

## Regras

A ordem de organização posfixa deve seguir as regras matematica

[ () ] > [ * e / ] > [ + e - ]

Exemplo simplificado que eu criei:
```C
while(1)
    {
        if ((teste1[i] >= 'A' && teste1[i] <= 'Z') || (teste1[i] >= 'a' && teste1[i] <= 'z'))
        {
            resultado[j] = teste1[i];

            ++j;
        };
        
        if (teste1[i] == '\0')
        {

            i = 0;

            while(1)
            {
                if (teste1[i] == '*' || teste1[i] == '/' || teste1[i] == '+' || teste1[i] == '-')
                {
                    resultado[j] = teste1[i];

                    ++j;
                }

                if (teste1[i] == '\0')
                {
                    printf("%s\n", resultado);
                    return 0;
                }

                ++i;
            }
            
        }

        ++i;
    }
```

