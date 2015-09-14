/*https://vijos.org/p/1057*/
#include <iostream>
#include <cstring>
using namespace std;

int dp[1002][1002];
int a[1002][1002];
int main(int argc, char const *argv[])
{
    int x, y, t;
    cin >> x >> y;
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(dp));
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            cin >> a[i][j];

    int maxV = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (a[i][j] == 1)
            {
                if (a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1])
                {
                    int left = dp[i][j - 1];
                    int up = dp[i - 1][j];
                    int lfup = dp[i - 1][j - 1];
                    dp[i][j] = min(min(left, up), lfup) + 1;
                }
                else
                    dp[i][j] = 1;
                if (dp[i][j] > maxV)
                    maxV = dp[i][j];
            }
        }
    }
    cout << maxV << endl;
    return 0;
}