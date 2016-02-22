#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000];
int main(int argc, char const *argv[])
{
    int kase, e, f, n, pw;
    int p[505], w[505], amt[505];
    
    cin >> kase;
    while (kase--)
    {
        cin >> e >> f >> n;
        pw = f - e;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i] >> w[i];
            amt[i] = pw / w[i];
        }

        for (int i = 0; i < 100000; i++)
            dp[i] = 0x7FFFFFF;

        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= pw; j++)
                if (j >= w[i])
                    dp[j] = min(dp[j], dp[j - w[i]] + p[i]);

        if (dp[pw] != 0x7FFFFFF)
            cout << "The minimum amount of money in the piggy-bank is " << dp[pw] << "." << endl;
        else
            cout << "This is impossible." << endl;
    }
    return 0;
}

/*
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4

The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/