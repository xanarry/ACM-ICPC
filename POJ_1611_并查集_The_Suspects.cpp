/*
http://poj.org/problem?id=1611
*/
#include <iostream>
using namespace std;

int p[30000];
int cn[30000];

int find_set(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = find_set(p[x]);
}

void union_set(int x, int y)
{
    int a = find_set(x);
    int b = find_set(y);
    if (a != b)
    {
        p[a] = b;
        cn[b] += cn[a];
    }

}

int main(int argc, char const *argv[])
{
    int n, m, a;
    while (cin >> n >> m)
    {
        if (!n && ! m) break;
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
            cn[i] = 1;
        }
        int k, first;
        for (int i = 0; i < m; i++)
        {
            cin >> k >> first;
            for (int j = 1; j < k; j++)
            {
                cin >> a;
                union_set(first, a);
            }
        }
        cout << cn[find_set(0)] << endl;
    }
    return 0;
}