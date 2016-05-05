#include <stdio.h>
#define MAXN 20000000
short flag[MAXN];
int primes[MAXN / 10], p = 0;

void genPrime()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (flag[i] == 0)
            primes[p++] = i;
        for (int j = 0; j < p && primes[j] * i <= MAXN; j++) //traverse primes that have already find
        {
            flag[primes[j] * i] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
    genPrime();
    int n;
    scanf("%d", &n);
    for (int i = p - 1; primes[i] >= 5; i--)
        if (primes[i] <= n && primes[i] == primes[i - 1] + 2)
            printf("%d %d\n", primes[i], primes[i - 1]);
    return 0;
}