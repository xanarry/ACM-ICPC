#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

/*
dp[i][j]表示1至max(i,j)都已经走过,并且第一个人在i,第二个人在j点时,
所要走的最短的距离,则dp[i][j] = dp[j][i]
*/
double f[1000][1000];

int main(int argc, char const *argv[])
{
    int n;
    int x[100], y[100];
    double d[100][100];
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];//输入顶点

        for (int i = 1; i <= n; i++)//计算任意两个顶点之间的距离
            for (int j = 1; j <= n; j++)
                d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        
        //为了保证i一定不小于j,所以i从大开始循环
        for (int i = n - 1; i >= 1; i--)
            for (int j = 1; j <= i; j++)//j不超过i
                if (i == n - 1)//边界条件, 即还有一步就到达n点了
                    f[i][j] = d[n][i] + d[n][j];//所以路径确定为i到n和j到n的距离
                else//从终点向起点计算, 当前点[i][j]的来源可以是[i+1][j]和[i+1][i],取从这两个来源以有的长度加上到当前点长度最小长度
                    f[i][j] = min(f[i + 1][j] + d[i + 1][i], f[i + 1][i] + d[i + 1][j]);
        
        printf("%.2f\n", f[2][1] + d[1][2]);
    }
    return 0;
}