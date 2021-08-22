#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void parte_da_tabela(int i, int j, int tabelinha_rs[], int quocientes[], int quantidade_termos, int a_fixo, int b_fixo) // 'i' para o array quocientes[] e 'j' para array tabelinha_rs[]
{
    while (i >= 0)
    {
        i--;
        tabelinha_rs[j + 1] = (quocientes[i] * tabelinha_rs[j]) + tabelinha_rs[j - 1];
        j++;
    }

    if (quantidade_termos % 2 == 0)
        tabelinha_rs[j - 2] = tabelinha_rs[j - 2] * (-1);
    else
        tabelinha_rs[j - 1] = tabelinha_rs[j - 1] * (-1);

    int maiorValor;
    int menorValor;
    if (abs(tabelinha_rs[j - 1]) >= abs(tabelinha_rs[j - 2]))
    {
        maiorValor = tabelinha_rs[j - 1];
        menorValor = tabelinha_rs[j - 2];
    }
    else
    {
        maiorValor = tabelinha_rs[j - 2];
        menorValor = tabelinha_rs[j - 1];
    }

    if (a_fixo < b_fixo)
    {
        if (maiorValor > b_fixo || maiorValor <= 0) //condição do valor de a barra em relação ao cara que tá no mod
        {
            while (maiorValor > b_fixo || maiorValor <= 0)
            {
                maiorValor += b_fixo;
            }
            printf("O inverso de %d mod %d = %d\n", a_fixo, b_fixo, maiorValor);
        }
        else
            printf("O inverso de %d mod %d = %d\n", a_fixo, b_fixo, maiorValor);
    }
    else
    {
        if (maiorValor > b_fixo || maiorValor <= 0) //condição do valor de a barra em relação ao cara que tá no mod
        {
            while (menorValor > b_fixo || menorValor <= 0)
                menorValor += b_fixo;
            printf("O inverso de %d mod %d = %d\n", a_fixo, b_fixo, menorValor);
        }
        else
            printf("O inverso de %d mod %d = %d\n", a_fixo, b_fixo, menorValor);
    }
}
void armazenar_valores(int a, int b, int quocientes[], int restos[], int i, int a_fixo, int b_fixo)
{
    while (restos[i] != 0)
    {
        i++;
        quocientes[i] = b / a;
        restos[i] = b % a;
        b = a;
        a = restos[i];
    }
    int tabelinha_rs[1000];
    tabelinha_rs[0] = quocientes[i - 1];
    tabelinha_rs[1] = (quocientes[i - 2] * tabelinha_rs[0]) + 1;

    parte_da_tabela(i - 2, 1, tabelinha_rs, quocientes, i, a_fixo, b_fixo);
}

void main()
{
    int a, b;
    int quocientes[1000];
    int restos[1000]; //1000 é aleatório.
    printf("Defina o valor de 'a': \t");
    scanf("%d", &a);
    printf("Defina o valor de 'b': \t");
    scanf("%d", &b);
    int x = a;
    int y = b;

    restos[0] = b % a;
    quocientes[0] = b / a;
    b = a;
    a = restos[0];

    armazenar_valores(a, b, quocientes, restos, 0, x, y);
}