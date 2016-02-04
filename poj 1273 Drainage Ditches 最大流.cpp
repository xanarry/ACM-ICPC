#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int capacity[300][300];//capacity
int parent[250];

int bfs(int s, int t)
{
    memset(parent, -1, sizeof(parent));
    int min_v = 0x7fffffff;
    queue<int> que;
    que.push(s);
    while (!que.empty() && que.front() != t)
    {
        int u = que.front();
        que.pop();
        for (int v = 1; v < 205; v++)//adjacent vertex
        {
            if (v != s && parent[v] == -1 && capacity[u][v] > 0)
            {
                que.push(v);
                parent[v] = u;
                min_v = min(min_v, capacity[u][v]);
            }
        }
    }
    return parent[t] == -1 ? -1 : min_v;
}


int main(int argc, char const *argv[])
{
    int ver, edg, u, v, c;
    while (~scanf("%d%d", &edg, &ver))
    {
        memset(capacity, 0, sizeof(capacity));
        for (int i = 0; i < edg; i++)
        {
            scanf("%d%d%d", &u, &v, &c);
            if (u == v)
                continue;
            capacity[u][v] += c;
        }

        int max_flow = 0;
        while (1)
        {
            int min_v = bfs(1, ver);
            if (min_v == -1)
                break;

            for (v = ver; parent[v] != -1; v = parent[v])
            {
                u = parent[v];
                capacity[u][v] -= min_v;
                capacity[v][u] += min_v;
            }
            max_flow += min_v;
        }
        printf("%d\n", max_flow);
    }
    return 0;
}
/*
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
*/