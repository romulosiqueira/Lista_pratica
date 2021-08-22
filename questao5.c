#include <stdio.h>

int funcaoMDC(int numero1, int numero2)
{
    if (numero2 == 0)
    {
        return numero1;
    }
    else
    {
        funcaoMDC(numero2, numero1 % numero2);
    }
}

int main()
{
    printf("Digite dois numeros:\n");
    int numero1, numero2;
    scanf("%d %d", &numero1, &numero2);
    printf("MDC(%d,%d) = %d\n", numero1, numero2, funcaoMDC(numero1, numero2));
    return 0;
}