/*
给定一个数n,输出1到n之间分解质因数后所有因数只有两种的数的个数
*/
#include <iostream>
#include <set>
using namespace std;

set<int> s;
void factories(int n)
{
    int i = 2;
    while (n >= 2)
    {
        if (n % i == 0)
        {
            s.insert(i);
            n /= i;
        }
        else
            i++;
    }
}

int a[3002] = {0};
int main(int argc, char const *argv[])
{
    int n;
    for (int i = 1; i <= 3000; i++)
    {
        int ctr = 0;
        factories(i);
        if (s.size() == 2)
            ctr++;
        a[i] += a[i - 1] + ctr;
        s.clear();
    }

    while (cin >> n)
        cout << a[n] << endl;
    return 0;
}