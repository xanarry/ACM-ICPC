#include <bits/stdc++.h>
using namespace std;

struct Bomb
{
    int v, k, c, l;
    Bomb(){}
    int operator< (const Bomb t) const
    {
        return v < t.v;
    }
} lamp[1005];

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
            cin >> lamp[i].v >> lamp[i].k >> lamp[i].c >> lamp[i].l;

        sort(lamp + 1, lamp + n + 1);
        int f[1005] = {0};
        int m[1005] = {0};
        for (int i = 1; i <= n; i++)
        {
            m[i] = m[i - 1] + lamp[i].l;
            f[i] = lamp[i].k + lamp[i].c * m[i];
            for (int j = 1; j <= i; j++)
                f[i] = min(f[i], f[j] + lamp[i].k + (m[i] - m[j]) * lamp[i].c);
        }
        cout << f[n] << endl;
    }
    return 0;
}
/*
6
94017 504 2 4
55203 270 5 68
120408 724 9 76
1668 765 6 53
70072 301 2 16
10544 779 8 34
0

2262
*/