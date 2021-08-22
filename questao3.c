#include <stdio.h>

int main()
{
    int n, divisor, potencia;
    printf("Digite um numero.\n");

    scanf("%d", &n);

    divisor = 2;
    while (n > 1)
    {
        potencia = 0;

        while (n % divisor == 0)
        {
            potencia++;
            n = n / divisor;
        }
        if (potencia != 0)
        {
            if (potencia == 1)
                printf("%d\n", divisor);
            else
                printf("%d^%d\n", divisor, potencia);
        }

        divisor++;
    }

    return 0;
}