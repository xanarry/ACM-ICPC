//http://codeforces.com/contest/615/problem/B
#include <cstring>
#include <vector>
#include <cstdio>
#define MAX(a,b) ((a)>(b)?a:b)
using namespace std;

vector<int> points[500000];
long long path[500000];
long long max_depth = 0;

long long dfs(int start)
{
    if (path[start])
        return path[start];
    else
        path[start] = 1LL;
    for (int i = 0; i < points[start].size(); i++)
        if (points[start][i] < start)
            path[start] = MAX(path[start], dfs(points[start][i]) + 1LL);
    return path[start];
}

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    long long max_v = 0;
    scanf("%d%d", &n, &m);//n points, m segments;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        points[a].push_back(b);
        points[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        max_v = MAX((long long)points[i].size() * dfs(i), max_v);
    printf("%I64d\n", max_v);
    return 0;
}
