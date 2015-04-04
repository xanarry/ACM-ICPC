/*描述
农民约翰的母牛总是生产出最好的肋骨。你能通过农民约翰和美国农业部标记在每根肋骨上的数字认出它们。
农民约翰确定他卖给买方的是真正的质数肋骨,是因为从右边开始切下肋骨,每次还剩下的肋骨上的数字都组成一个质数,举例来说:
7 3 3 1
全部肋骨上的数字 7331是质数;三根肋骨 733是质数;二根肋骨 73 是质数;当然,最后一根肋骨 7 也是质数。
7331 被叫做长度 4 的特殊质数。
写一个程序对给定的肋骨的数目 N (1<=N<=8),求出所有的特殊质数。数字1不被看作一个质数。

输入格式：
多组数据输入。单独的一行包含N。

输出格式：
按顺序输出长度为 N 的特殊质数,每行一个。
并按大小顺序排列(从小到大).

样例
样例输入
4

样例输出
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393*/
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

bool issuper(int n)
{
    while (n > 0)
    {
        if (!isprime(n))
            return false;
        else
            n /= 10;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int min = pow(10, n - 1);
        int max = pow(10, n) - 1;
        for (int i = min; i <= max; i++)
        {
            if (issuper(i))
                cout << i << endl;
        }
    }
    return 0;
}