#include <stdio.h>

int mdc(int a, int b)
{
    int oldA = a;
    int oldB = b;
    int auxm;
    if (a > b)
    {
        auxm = a;
        a = b;
        b = auxm;
    }

    int soma = 0;
    int resto = a;
    int s = 1;
    int t = 1;
    int aux, x, u, p;
    int arr[100];
    int arrdois[100];

    int index = 0;

    while (resto != 0)
    {
        arr[index] = a / b;

        resto = a % b;

        aux = a;
        a = b;
        b = resto;
        index++;
    }

    for (int i = index - 2; i >= 0; i--)
    {

        if (index <= 3)
        {

            if (i == 1)
            {

                arrdois[0] = arr[i];
            }
        }
        else
        {
            if (i == index - 2)
            {

                soma = arr[i] * 1;
                arrdois[i] = soma;
            }
            else if (i == index - 3)
            {
                soma = arr[i] * arrdois[i + 1] + 1;
                arrdois[i] = soma;
            }
            else
            {
                soma = arr[i] * arrdois[i + 1] + arrdois[i + 2];
                arrdois[i] = soma;
            }
        }
    }

    if (index <= 3)
    {
        u = 1;
        p = arrdois[0];
    }
    else
    {
        p = arrdois[1];

        u = arrdois[0];
    }

    if (oldA > oldB)
    {
        if (u > p)
        {

            if ((index - 2) % 2 == 0)
            {
                u = -u;
            }
            else
            {
                p = -p;
            }

            s = p;
            t = u;
        }
        else
        {
            if ((index - 2) % 2 == 0)
            {
                u = -u;
            }
            else
            {
                p = -p;
            }

            s = u;
            t = p;
        }
    }
    else
    {
        if (u > p)
        {

            if ((index - 2) % 2 == 0)
            {
                u = -u;
            }
            else
            {
                p = -p;
            }

            s = u;
            t = p;
        }
        else
        {

            if ((index - 2) % 2 == 0)
            {

                u = -u;
            }
            else
            {
                p = -p;
            }

            s = p;
            t = u;
        }
    }

    // if (arrdois[2] > arrdois[1])
    // {
    //     s = arrdois[2];
    //     t = arrdois[1];
    // }
    // else
    // {
    //     s = arrdois[1];
    //     t = arrdois[2];
    // }

    printf("s: %d ", s);
    printf("\n");

    printf("t: %d ", t);
    printf("\n");

    printf("%d = %d*%d + %d*%d  ", (s * oldA + t * oldB), s, oldA, t, oldB);
}

int main()
{
    int a, b;
    printf("Escreva dois numeros: \n");
    scanf("%d %d", &a, &b);
    mdc(a, b);
}