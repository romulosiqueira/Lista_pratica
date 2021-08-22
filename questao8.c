#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parte_da_tabela(int i, int j, int tabelinha_rs[], int quocientes[], int quantidade_termos, int a_fixo, int b_fixo) // 'i' para o array quocientes[] e 'j' para array tabelinha_rs[]
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
                maiorValor += b_fixo;
            return maiorValor;
        }
        else
            return maiorValor;
    }
    else
    {
        if (menorValor > b_fixo || menorValor <= 0) //condição do valor de a barra em relação ao cara que tá no mod
        {
            while (menorValor > b_fixo || menorValor <= 0)
                menorValor += b_fixo;
            return menorValor;
        }
        else
            return menorValor;
    }
}
int armazenar_valores(int a, int b, int quocientes[], int restos[], int i, int a_fixo, int b_fixo)
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

    return parte_da_tabela(i - 2, 1, tabelinha_rs, quocientes, i, a_fixo, b_fixo);
}
int mdc(int a, int m) //algoritmo de euclides
{
    if (a % m == 0)
        return m;
    return mdc(m, a % m); //recursividade
}

void main()
{
    int a, b, m;
    int quocientes[1000];
    int restos[1000]; //1000 é aleatório.
    printf("Defina o valor de 'a': \t");
    scanf("%d", &a);
    printf("Defina o valor de 'b': \t");
    scanf("%d", &b);
    printf("Defina o valor de 'm': \t");
    scanf("%d", &m);
    int mdc_am = mdc(a, m);
    if (b % mdc_am != 0)
        printf("Nao existe solucao\n");
    else
    {
        if (mdc_am == 1) //caso o mdc seja, terá apenas uma solução...
        {
            int a_fixo = a;
            int b_fixo = b;
            int m_fixo = m;
            restos[0] = m % a;
            quocientes[0] = m / a;
            m = a;
            a = restos[0];
            int solucao = b_fixo * armazenar_valores(a, m, quocientes, restos, 0, a_fixo, m_fixo); //vai retornar o inverso (a_barra)

            if (solucao > m_fixo)
                solucao = solucao % m_fixo;
            printf("Solucao = {%d}\n", solucao);
        }
        else //...caso não seja...:(
        {
            int a_fixo = a;
            int b_fixo = b;
            int m_fixo = m;
            int solucoes[mdc_am];
            int novo_a = a / mdc_am;
            int novo_b = b / mdc_am;
            int novo_m = m / mdc_am;
            int novo_a_fixo = novo_a;
            int novo_b_fixo = novo_b;
            int novo_m_fixo = novo_m;
            restos[0] = novo_m % novo_a;
            quocientes[0] = novo_m / novo_a;
            novo_m = novo_a;
            novo_a = restos[0];
            int solucao = novo_b_fixo * armazenar_valores(novo_a, novo_m, quocientes, restos, 0, novo_a_fixo, novo_m_fixo); //vai retornar o inverso (a_barra)

            if (solucao > novo_m_fixo)
                solucao = solucao % novo_m_fixo;
            solucoes[0] = solucao; //solução única.
            int i;
            char c;

            for (i = 1; i < mdc_am; i++) //ler todas as soluções
            {
                solucoes[i] = solucoes[0] + novo_m_fixo * i;
                if (solucoes[i] > m_fixo)
                    solucoes[i] = solucoes[i] % m_fixo;
            }
            printf("Solucao = {");
            for (i = 0; i < mdc_am; i++)
            {
                c = (i == mdc_am - 1) ? '}' : ',';
                printf("%d%c", solucoes[i], c);
            }
            printf("\n");
        }
    }
}