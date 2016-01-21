//http://codeforces.com/contest/608/problem/A
#include <iostream>
using namespace std;

int a[11000];
int main(int argc, char const *argv[])
{
    int n, m, c, s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> s;
        a[c] = s > a[c] ? s : a[c];
    }

    int t = 0;
    while (m > 0)
    {
        if (a[m] && t < a[m])
            t += (a[m] - t);
        t++;
        m--;
    }
    cout << t << endl;
    return 0;
}