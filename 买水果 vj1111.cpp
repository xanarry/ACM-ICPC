#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int lcs(string a, string b)
{
    int dp[105][105];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= a.length(); i++)
        for (int j = 1; j <= b.length(); j++)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[a.length()][b.length()];
}

int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a)
    {
        cin >> b;
        int lcsLen = lcs(a, b);
        cout << a.length() + b.length() - lcsLen << endl;
    }
    return 0;
}