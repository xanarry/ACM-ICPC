//http://codeforces.com/problemset/problem/610/B
#include <iostream>
using namespace std;

long long a[200010];
long long min_v = 1e9+1;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min_v)
            min_v = a[i];
    }

    int max_seg = -100;
    for (int i = 0; i < n; i++)
    {
        int tans = 0;
        if (a[i] == min_v)
            while (a[(i + (++tans)) % n] > min_v);
        if (tans > max_seg)
            max_seg = tans;
    }
    cout << min_v * n + max_seg - 1;
    return 0;
}