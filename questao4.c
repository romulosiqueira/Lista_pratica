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
int funcaoprimo(int numero, int contador)
{
    if (numero == 0 || numero == 1)
        return 0;
    if (contador == numero)
        return 1;
    if (numero % contador == 0)
        return 0;
    else if (contador < numero)
        funcaoprimo(numero, contador + 1);
}

int funcaomenorprimo(int numero, int contador)
{
    if (contador <= numero)
    {
        if (funcaoprimo(contador, 2) == 1 && numero % contador == 0)
        {
            return contador;
        }
        else
        {
            contador++;
            funcaomenorprimo(numero, contador);
        }
    }
    else
    {
        return 0;
    }
}

int funcaoanalise(int numero, int menorprimo)
{
    if (numero != 1)
    {
        printf(" x %d", menorprimo);
        numero = (numero / menorprimo);
        menorprimo = funcaomenorprimo(numero, 1);
        funcaoanalise(numero, menorprimo);
    }
    else
    {
        return 0;
    }
}

int funcaoMMC(int numero1, int numero2)
{

    int mmc, aux, i;

    for (i = 2; i <= numero2; i++)
    {
        aux = numero1 * i;
        if ((aux % numero2) == 0)
        {
            mmc = aux;
            i = numero2 + 1;
        }
    }
    return mmc;
}
int main()
{
    int numero1, numero2, parametro, numero3, parametro2, numero4;
    printf("Digite dois numeros:\n");
    scanf("%d %d", &numero1, &numero2);
    printf("MDC[%d,%d] =", numero1, numero2);
    parametro = funcaoMDC(numero1, numero2);
    printf(" %d", funcaomenorprimo(parametro, 1));
    numero3 = (parametro / funcaomenorprimo(parametro, 1));
    if (numero3 != 1)
    {
        funcaoanalise(numero3, funcaomenorprimo(numero3, 1));
    }
    printf(".\n");

    printf("MMC[%d,%d] =", numero1, numero2);
    parametro2 = funcaoMMC(numero1, numero2);
    printf(" %d", funcaomenorprimo(parametro2, 1));
    numero4 = (parametro2 / funcaomenorprimo(parametro2, 1));
    if (numero4 != 1)
    {
        funcaoanalise(numero4, funcaomenorprimo(numero4, 1));
    }
    printf(".\n");

    return 0;
}