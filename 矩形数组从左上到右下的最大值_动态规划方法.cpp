/*
输入一个n*n的二维数组, 从左上角走到右下角,一次只能向下或者向右, 求该路径上所有数的最大值
*/
#include <iostream>
#include <cstring>
#define MAX(x, y) ((x)>(y)?(x):(y))
using namespace std;

const int N = 100;
int dp[N + 1][N + 1];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dp[i][j];
            dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]) + dp[i][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
/*
6
200 120 400 150 180 300
150 250 360 120 200 130
350 300 250 100 500 260
100 300 260 320 100 150
500 130 260 100 200 170
160 100 250 200 600 200
3100

3
1 2 1
1 2 4
3 2 1
10
*/