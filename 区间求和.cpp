#include <iostream>
#include <cstdio>
#define MAX 1000050
using namespace std;
int tree[MAX];
int n;//共有n个数
inline int lowbit(int x)
{
    return (x&-x);
}
void add(int x,int value)//a[x]增加value
{
    int i;
    for(i=x;i<=n;i+=lowbit(i))
      tree[i]+=value;
}
int getres(int x)//求a[1]~a[i]的和
{
    int i,sum=0;
    for(i=x;i;i-=lowbit(i))
      sum+=tree[i];
    return sum;
}

int main()
{
    int m, a, b, t;
    char opt[10];
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", opt);
        if (opt[0] == 'g')//输出数组中的一个元素
        {
            cin >> a;
            printf("%d\n", getres(a));
        }
        else //更新一段数组中的元素
        {
            cin >> a >> b >> t;
            add(a, t);
            add(b + 1, -t);
        }
    }
    return 0;
}