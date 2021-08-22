
#include <stdio.h>

int funcao(int numero, int contador)
{
    if (numero == 0 || numero == 1)
        return 0;
    if (contador == numero)
        return 1;
    if (numero % contador == 0)
        return 0;
    else if (contador < numero)
        funcao(numero, contador + 1);
}
int main()
{
    int numero, resultado;
    printf("Digite o numero:\n");
    scanf("%d", &numero);
    resultado = funcao(numero, 2);
    if (resultado == 0)
    {
        printf("nao eh primo\n");
    }
    else
    {
        printf("eh primo\n");
    }
    return 0;
}