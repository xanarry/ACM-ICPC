//http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=29248
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                cin >> dp[i][j];

        for (int i = n - 1; i >= 1; i--)
            for (int j = 1; j <= i; j++)
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
        cout << dp[1][1] << endl;
    }
    return 0;
}
/*
6
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
1 2 4 5 7 3
*/