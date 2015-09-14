#include <iostream>
#include <cstring>
using namespace std;

int dp[3001];
int m = 0;
int main(int argc, char const *argv[])
{
    int n, a;
    while (cin >> n)
    {
        m = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            int min_v = 0x7fffffff, index = -1;
            for (int j = 0; j < m; j++)
                if (a < dp[j] && dp[j] - a < min_v)
                {
                    min_v = dp[j] - a;
                    index = j;
                }

            if (index == -1)
                dp[m++] = a;
            else
                dp[index] = a;
        }
        cout << m << endl;
    }
    return 0;
}