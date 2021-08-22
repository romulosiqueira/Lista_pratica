#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void entrada(int vetor[], int contador, int tamanho, int contador2)
{
    if (contador < tamanho)
    {
        if (contador % 2 == 0)
        {
            printf("Digite o resto %d: ", contador2);
            scanf("%d", &vetor[contador]);
        }
        else
        {
            printf("Digite o divisor %d: ", contador2);
            scanf("%d", &vetor[contador]);
            contador2++;
        }
        contador++;
        entrada(vetor, contador, tamanho, contador2);
    }
    else
        return;
}

int funcaomdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        funcaomdc(b, a % b);
}

int funcaoanalisedivisores(int vetor[], int contador, int tamanho, int soma)
{
    if (contador < tamanho)
    {
        if (contador % 2 != 0)
        {
            if (vetor[contador] == 0)
            {
                soma = soma + 1;
            }
        }
        contador++;
        funcaoanalisedivisores(vetor, contador, tamanho, soma);
    }
    else
    {
        return soma;
    }
}

int funcaoanaliseprimos(int vetor[], int contador, int tamanho, int constante, int contador2, int soma)
{
    if (contador < tamanho - 2)
    {
        if (contador % 2 != 0)
        {
            if (contador2 <= constante)
            {
                int a, b;
                a = vetor[contador];
                b = vetor[contador + 2 * contador2];
                if (funcaomdc(a, b) > 1)
                {
                    soma = soma + 1;
                }
                contador2++;
                funcaoanaliseprimos(vetor, contador, tamanho, constante, contador2, soma);
            }
            else
            {
                contador++;
                contador2 = 1;
                constante--;
                funcaoanaliseprimos(vetor, contador, tamanho, constante, contador2, soma);
            }
        }
        else
        {
            contador++;
            funcaoanaliseprimos(vetor, contador, tamanho, constante, contador2, soma);
        }
    }
    else
    {
        return soma;
    }
}

int funcaosomarM(int vetor[], int contador, int tamanho, int multiplicacao)
{
    if (contador < tamanho)
    {
        if (contador % 2 != 0)
        {
            multiplicacao = multiplicacao * vetor[contador];
        }
        contador++;
        funcaosomarM(vetor, contador, tamanho, multiplicacao);
    }
    else
    {
        return multiplicacao;
    }
}

int funcaoresto(int contador, int a, int c, int retorno)
{
    if (contador < 10000)
    {
        if ((a * contador) % c == 1)
        {
            retorno = contador;
            contador = 10000;
        }
        contador++;
        funcaoresto(contador, a, c, retorno);
    }
    else
    {
        return retorno;
    }
}

int funcaoteorema(int vetor[], int contador, int tamanho, int soma)
{
    if (contador < tamanho)
    {
        if (contador % 2 == 0)
        {
            int parte1, parte2, parte3, parte4, proximo;
            proximo = vetor[contador + 1];
            parte1 = ((funcaosomarM(vetor, 0, tamanho, 1)) / (proximo));
            parte2 = ((funcaosomarM(vetor, 0, tamanho, 1)) / (proximo)) % (proximo);
            parte3 = funcaoresto(0, parte2, proximo, 0);
            parte4 = (vetor[contador]) * (parte1)*parte3;
            soma = soma + parte4;
        }
        contador++;
        funcaoteorema(vetor, contador, tamanho, soma);
    }
    else
    {
        return soma;
    }
}

int main()
{
    int tamanho, quantidade, contador, decisao;
    printf("A quantidade de congruencias é: 3\n");
    quantidade = 3;
    tamanho = 2 * quantidade;
    int vetor[tamanho];
    entrada(vetor, 0, tamanho, 1);
    if (funcaoanalisedivisores(vetor, 0, tamanho, 0) > 0)
    {
        printf("Divisores iguais a zero.");
    }
    else
    {
        int constante;
        constante = (quantidade - 1);
        if (funcaoanaliseprimos(vetor, 0, 6, constante, 1, 0) > 0)
        {
            printf("Divisores nao sao primos entre si.\n");
        }
        else
        {
            printf("solução = S;\n");
            printf("S = %d (mod %d);\n", funcaoteorema(vetor, 0, tamanho, 0) % funcaosomarM(vetor, 0, tamanho, 1), funcaosomarM(vetor, 0, tamanho, 1));
            printf("S = %d x q + %d. que pertence aos Reais.\n", funcaosomarM(vetor, 0, tamanho, 1), funcaoteorema(vetor, 0, tamanho, 0) % funcaosomarM(vetor, 0, tamanho, 1));
            printf("Ou seja, S = %d.\n", funcaoteorema(vetor, 0, tamanho, 0) % funcaosomarM(vetor, 0, tamanho, 1));
        }
    }
    return 0;
}