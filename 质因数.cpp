/*描述
已知正整数n是两个不同的质数的乘积，试求出较大的那个质数。
输入格式
多组数据输入。输入只有一行，包含一个正整数n。
输出格式
输出只有一行，包含一个正整数p，即较大的那个质数。
样例输入
21
样例输出
7
提示
对于60%的数据，6 ≤ n ≤ 1000。 对于100%的数据，6 ≤ n ≤ 2 * 10^9。
*/
#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int m;
        int s = sqrt(n);
        for (m = s; m >= 2; m--)
            if (isprime(m) && (n % m == 0)) {cout << n / m << endl; break;}
    }
    return 0;
}