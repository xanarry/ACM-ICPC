//http://codeforces.com/problemset/problem/610/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    long long t = n / 2;
    if (t * 2 != n)
        cout  << 0;
    else
    {
        n = t / 2;
        if (n * 2 == t)
            cout << n - 1;
        else
            cout << n;
    }
    return 0;
}