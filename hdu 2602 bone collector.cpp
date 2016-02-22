#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int v[1005], w[1005], dp[1005][1005];
int main(int argc, char const *argv[])
{
    int kase, n, c;
    cin >> kase;
    while (kase--)
    {
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        for (int i = 1; i <= n; i++)
            cin >> v[i];

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = c; j >= v[i]; j++)
                if (j >= v[i])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
                else
                    dp[i][j] = dp[i - 1][j];
        cout << dp[n][c] << endl;
    }
    return 0;
}