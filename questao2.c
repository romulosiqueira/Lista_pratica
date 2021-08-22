#include <stdio.h>
#include <time.h>

void primo(long long int n, long long int antecessor_n)
{
    if (antecessor_n == 1)
        printf("%lld ", n);
    else
        n % antecessor_n == 0 ?: primo(n, antecessor_n - 1);
}

void main()
{
    time_t x;
    time(&x);

    long long int n = 2;
    while (difftime(time(NULL), x) < 60)
    {
        primo(n, n - 1);
        n++;
    }
    printf("tempo de execução %lf\n", difftime(time(NULL), x));
}
