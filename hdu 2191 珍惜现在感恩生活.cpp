#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int c, m, n;
    int p[110], w[110], cnt[110], dp[110][110];
    cin >> c;
    while (c--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
            cin >> p[i] >> w[i] >> cnt[i];

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= cnt[i]; k++)
                    if (j >= k * p[i])//当前状态的背包在前i-1中物品的最大值基础上加上对新物品取0,1,2...cnt[i]后得到的最大值
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * p[i]] + k * w[i]);

        cout << dp[m][n] << endl;
    }
    return 0;
}

/*
1
8 2
2 100 4
4 100 2
400
*/

