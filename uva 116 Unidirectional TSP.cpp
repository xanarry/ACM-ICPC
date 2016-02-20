//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=52
#include <iostream>
#include <algorithm>
using namespace std;

int a[32][102];
int dp[32][102];
int m, n, p, v, res;

int main(int argc, char const *argv[])
{
    while (cin >> m >> n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                dp[i][j] = 0x7FFFFFF;
            }
        }

        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                for (int k = -1; k <= 1; k++)
                {
                    int t = i - k;
                    if (t >= m)
                        t = 0;
                    else if (t < 0)
                        t = m - 1;
                    if (j == n - 1)
                        dp[i][j] = a[i][j];
                    else
                        dp[i][j] = min(dp[i][j], dp[t][j + 1] + a[i][j]);
                }
            }
        }

        v = dp[0][0];
        p = 0;
        for (int i = 1; i < m; i++)
            if (dp[i][0] < v)
            {
                v = dp[i][0];
                p = i;
            }

        res = v;
        cout << p + 1;
        for (int j = 1; j < n; j++)
        {
            v = 0x7FFFFFF;
            int tmp = p;
            for (int k = -1; k <= 1; k++)
            {
                int t = p + k;
                if (t > m - 1)
                    t = 0;
                if (t < 0 && dp[m - 1][j] < v)
                    t = m - 1;
                if (t >= 0 && t <= m - 1 && dp[t][j] <= v)
                {
                    if (dp[t][j] < v)
                    {
                        v = dp[t][j];
                        tmp = t;
                    }
                    else if (t < tmp)
                        tmp = t;
                }
            }
            p = tmp;
            if (j < n)
                cout << " ";
            cout << p + 1;
        }
        cout << "\n" << res << endl;
    }
    return 0;
}
