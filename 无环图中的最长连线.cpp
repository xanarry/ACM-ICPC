//给一个有点和线连接的图, 点的个数在[2, 1000]之间, 两个点通过一条直线连接, 图中保证不会出现环, 请你在图中找出一条最长的连线, 并输出这条连线上的顶点数

#include <iostream>
#include <vector>
#include <cstring>
#define MAX(x,y) ((x)>(y)?(x):(y))

using namespace std;

vector<int> point[20005];
int pathlen[20005];

int dfs(int s, int par)
{
    if (pathlen[s] != 0)
        return pathlen[s];
    else
        pathlen[s] = 1;

    int maxl = 0, i;
    for (i = 0; i < point[s].size(); i++)
        if (point[s][i] != par)
            pathlen[s] = MAX(pathlen[s], dfs(point[s][i], s) + 1);
    return pathlen[s];
}

int main()
{
    int m, n, u, v;
    cin >> m >> n;//points and edges
    while (n--)
    {
        cin >> u >> v;
        point[u].push_back(v);
        point[v].push_back(u);
    }

    int ml = -1;
    for (int i = 0; i < m; i++)
    {
        if (point[i].size() == 1)
        {
           memset(pathlen, 0, sizeof(pathlen));
           ml = MAX(ml, dfs(i, i));
        }
    }
    cout << ml << endl;
}