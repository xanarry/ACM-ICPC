/*http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19499*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    int cn;
    while (cin >> cn && cn != -1)
    {
        while (cn--)
        {
            cin >> n >> m;
            int sum = 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (m % 2 != 0)
                {
                    sum *= 2;
                    m = (m + 1) / 2;
                }
                else
                {
                    sum = sum * 2 + 1;
                    m /= 2;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}