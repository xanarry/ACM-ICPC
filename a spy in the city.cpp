#include <iostream>
#include <cstring>
using namespace std;

int dp[4000][60];
int state[4000][60][2];

int main(int argc, char const *argv[])
{
    int n, t, m1, m2;
    int lap[100], d1[100], d2[100];
    int cnt = 0;
    while (cin >> n && n)
    {
        memset(state, 0, sizeof(state));
        cin >> t;
        for (int i = 1; i <= n - 1; i++)
            cin >> lap[i];

        cin >> m1;
        for (int i = 1; i <= m1; i++)
        {
            cin >> d1[i];
            int tmp = d1[i];
            state[tmp][1][0] = 1;
            for (int j = 1; j <= n - 1; j++)
            {
                tmp += lap[j];
                state[tmp][j + 1][0] = 1;
            }
        }

        cin >> m2;
        for (int i = 1; i <= m2; i++)
        {
            cin >> d2[i];
            int tmp = d2[i];
            state[tmp][n][1] = -1;
            for (int j = n - 1; j >= 1; j--)
            {
                tmp += lap[j];
                state[tmp][j][1] = -1;
            }
        }

        for (int i = 0; i < 4000; i++)
            for (int j = 0; j < 60; j++)
                dp[i][j] = 0x7ffffff;

        dp[0][1] = 0;//dp[i][j]则表示i时刻在车站j，已经等车的时间（应该取最小）
        for (int i = 0; i < t; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //一共三个决策, 需要把三个决策分别算出来并保存到状态, 并不是只选择其中一个
                dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);//不动, 原地等待1分钟, 时间加1
                if (j < n && state[i][j][0] != 0 && i + lap[j] <= t)//向右行
                    dp[i + lap[j]][j + 1] = min(dp[i + lap[j]][j + 1], dp[i][j]);
                if (j > 1 && state[i][j][1] != 0 && i + lap[j - 1] <= t)//向左行
                    dp[i + lap[j - 1]][j - 1] = min(dp[i + lap[j - 1]][j - 1], dp[i][j]);
            }
        }
        cout << "Case Number " << ++cnt << ": ";
        if (dp[t][n] >= 0x7ffffff)
            cout << "impossible" << endl;
        else
            cout << dp[t][n] << endl;
    }
    return 0;
}

/*
4
55
5 10 15
4
0 5 10 20
4
0 5 10 15

4
18
1 2 3
5
0 3 6 10 12
6
0 3 5 7 12 15

2
30
20
1
20
7
1 3 5 7 11 13 17

0
*/