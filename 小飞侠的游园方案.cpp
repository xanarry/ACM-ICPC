//https://vijos.org/p/1025
#include <iostream>
#include <cstring>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

int lv[1001];
int tv[1001];
int dp[1001][1001];
int main(int argc, char const *argv[])
{
    int n, t;
    memset(dp, 0, sizeof(dp));
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> lv[i] >> tv[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j >= tv[i])
                dp[i][j] = MAX(dp[i - 1][j], lv[i] + dp[i - 1][j - tv[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][t] << endl;
    return 0;
}
/*
5
10
1 2
5 5
4 3
3 2
6 7

3
5
1 2
5 5
4 3
*/