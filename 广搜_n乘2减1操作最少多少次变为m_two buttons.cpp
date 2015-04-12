#include <iostream>
#include <queue>
using namespace std;
int vis[10005];
queue<int> q;
int n,m;
inline bool check(int a,int x)
{
    if(a>10000||a<0)return false;
    if(a==m)return true;
    if(vis[a])return false;
    vis[a]=vis[x]+1;
    q.push(a);
    return false;
}

int main()
{
    cin>>n>>m;
    q.push(n);
    vis[n]=1;
    while(true)
    {
        int x=q.front();q.pop();
        if(check(x-1,x)||check(x*2,x))
        {
            cout<<vis[x]<<endl;
            return 0;
        }
    }
}
