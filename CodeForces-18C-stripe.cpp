/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=22889
description:给定一个数列,查找能找到多少个点将该数列分为两段切值相同
使用前缀和数组,因为找到一个点分成两段后必然有数列一段的和乘以2值等于总和
*/
#include <iostream>
#define MAXN 100000+10

using namespace std;

int a[MAXN];
int s[MAXN];

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
            if (s[n] == s[i] * 2)
                ans++;
        cout << ans << endl;
    }
    return 0;
}