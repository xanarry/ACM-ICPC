/*
输入n，k
判断小于等于n的所有素数中，有多少个素数的值等于2个连续素数的之和再加1，满足情况的次数大于等于k，输出yes，否则输出no
input
27 2
45 7
output
yes
no
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> v;
int main(int argc, char const *argv[])
{
    for (int i = 2; i <= 1000; i++)
        if (isprime(i))
            v.push_back(i);

    int n, k;
    while (cin >> n >> k)
    {
        int ctr = 0;
        for (int i = 0; v[i] <= n; i++)
        {
            int sum = 0;
            for (int j = 0; j < k; j++)
                sum += v[i + j];
            
            if (sum + 1 <= n && isprime(sum + 1))
                ctr++;
        }

        if (ctr >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}