/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=38784
问题是这样的：一个十进制数，如果是素数，而且它的各位数字和也是素数，则称之为“美素数”，如29，本身是素数，而且2+9 = 11也是素数，所以它是美素数。 
给定一个区间，你能计算出这个区间内有多少个美素数吗？
第一行输入一个正整数T，表示总共有T组数据(T <= 10000)。 
接下来共T行，每行输入两个整数L，R(1<= L <= R <= 1000000)，表示区间的左值和右值。
*/
#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 1000000;
int ans[maxn + 5];

bool isprime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool allprime(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    if (isprime(sum))
        return true;
    else
        return false;
}

void Init ()
{
    int i;
    for (i = 2; i < maxn; i++)
        if (isprime(i) && allprime(i))
            ans[i] = ans[i - 1] + 1;
        else
            ans[i] = ans[i - 1];
}

int main()
{
    int t, i = 1;
    Init ();
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i++ << ": " << ans[b] - ans[a - 1] << endl;
    }

    return 0;
}