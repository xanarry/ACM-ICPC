#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct edge
{
    int u, v, w;
    int operator< (edge a) const 
    {
        return w < a.w;
    } 
};

edge edges[200005];
int p[200005];

int find( int x)
{
    if (x == p[x])
        return p[x];
    else
        return p[x] = find(p[x]);
}

int cnt[200005];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    int n, m, k;//n个点,m条边
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)//输入每条边两端的顶点和权重
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    long long len = 0;
    for (int i = 0; i < m; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (u != v)
        {
            len += edges[i].w;
            p[v] = u;
        }
    }
    int x=find(k),cnt=0;
    for (int i = 1; i <= n; i++)
        if(find(i)==x)
            cnt++;
    if(cnt!=n)
        len=n-cnt;
    cout<<len<<endl;
    return 0;
}
