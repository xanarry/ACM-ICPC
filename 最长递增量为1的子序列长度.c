#include <stdio.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

int len[100005];
int a[100005];

int main()
{
    int n, maxl = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        len[a[i]] = MAX(len[a[i]], len[a[i] - 1] + 1);
        if (len[a[i]] > maxl)
            maxl = len[a[i]];
    }
    printf("%d\n", maxl);
    return 0;
}