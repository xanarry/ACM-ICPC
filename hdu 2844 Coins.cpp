#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int main(int argc, char const *argv[])
{
    /*多重背包, 数量很大通过二进制方法优化复杂度
    题目要求算出硬币能够恰好组成1到m中的多少, 所以
    只对当前的价值正好等于上一个价值加上新的银币时
    才做处理*/
    int m, n, v, w[1000];
    while (true)
    {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
            break;
        vector<int> value;
        for (int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &v);
            for (int k = 1; k <= v; k <<= 1)
            {
                value.push_back(w[i] * k);
                v -= k;
            }
            if (v > 0)
                value.push_back(w[i] * v);
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < value.size(); i++)
            for (int j = m; j >= value[i]; j--)
                if (j == dp[j - value[i]] + value[i])
                    dp[j] = dp[j - value[i]] + value[i];
        int sum = 0;
        for (int j = 0; j <= m; j++)
            if (dp[j] > 0)
                sum++;
        printf("%d\n", sum);
    }
    return 0;
}

/*
3 10
1 2 4 2 1 1
-->8
2 5
1 4 2 1
-->4
0 0
*/
