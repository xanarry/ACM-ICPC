/*
http://poj.org/problem?id=1182
*/
#include <iostream>
#include <cstdio>
using namespace std;

int p[150010];
int find_set(int x)
{
    if (p[x] == x)
        return x;
    else
        return p[x] = find_set(p[x]);
}

void union_set(int a, int b)
{
    int x = find_set(a);
    int y = find_set(b);
    if (x != b)
        p[x] = y;
}

int main(int argc, char const *argv[])
{
    int n, k;
    int t, x, y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n * 3; i++)
        p[i] = i;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &t, &x, &y);
        if (x > n || y > n || (t == 2 && x == y))
            sum++;
        else if (t == 1)//same type
        {
            if (find_set(x) == find_set(y + n) || find_set(x) == find_set(y + 2 * n))
                sum++;
            else
            {
                union_set(x, y);
                union_set(x + n, y + n);
                union_set(x + 2 * n, y + 2 * n);
            }
        }
        else//x eat y
        {
            if (find_set(x) == find_set(y) || find_set(x) == find_set(y + 2 * n))
                sum++;
            else
            {
                union_set(x, y + n);
                union_set(x + n, y + 2 * n);
                union_set(x + 2 * n, y);
            }
        }   
    }
    printf("%d\n", sum);
    return 0;
}