
/*http://acm.hust.edu.cn/vjudge/contest/view.action?cid=68966#problem/G*/
#include <cstring>
#include <cstdio>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

int m[100001][11];//某一时间某个点的馅饼数量
int dp[100001][11];
int main(int argc, char const *argv[])
{
    int n, x, t;
    while (scanf("%d", &n) == 1 && n)
    {
        int ans = -1;
        memset(dp, 0, sizeof(dp));
        memset(m, 0, sizeof(m));
        int maxt= -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &t);
            if (t > maxt)
                maxt = t;
            m[t][x]++;//输入时间坐标并标记
        }

        for (int i = 1; i <= maxt; i++)//遍历所有时间
        {
            for (int j = 0; j <= 10; j++)//遍历所有左边
            {
                if (j >= 5 - i && j <= 5 + i)//在该秒可以达到的点才有效, 比如第一秒不能取得坐标0的馅饼
                {
                    for (int k = -1; k <= 1; k++)//在上一次可能的位置找到最低的一个点
                        if (j + k <= 10 && j + k >= 0)
                            dp[i][j] = MAX(dp[i - 1][j + k] + m[i][j], dp[i][j]);
                    if (dp[i][j] > ans)
                        ans = dp[i][j];//标记全局最大值
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}