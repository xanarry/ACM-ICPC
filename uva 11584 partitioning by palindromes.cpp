#include <bits/stdc++.h>
using namespace std;

bool isp[1001][1001];
char a[1003];

bool pal(int i, int j)
{
    for (; i < j; i++, j--)
        if (a[i] != a[j])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    int n, f[1002], len;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", a);
        len = strlen(a);
        for (int i = 0; i < len; i++)
            for (int j = 0; j <= i; j++)
                isp[j][i] = pal(j, i);

        f[0] = 1;
        for (int i = 1; i < len; i++)
        {
            f[i] = i + 1;
            for (int j = 0; j <= i; j++)
                if (isp[j][i])
                    f[i] = min(j - 1 < 0 ? 1 : f[j - 1] + 1, f[i]);
        }
        printf("%d\n", f[len - 1]);
    }
    return 0;
}

/*
3
racecar
fastcar
aaadbccb
amadam
madama
zzxzcc
qwerty
zzxxxz
zxxxzz
zxzczxxzc
*/