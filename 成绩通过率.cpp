#include <iostream>
#include <algorithm>
using namespace std;

int a[1000];
int main(int argc, char const *argv[])
{
    int n, cnt, rate;
    cin >> n;
    while (n--)
    {
        cin >> cnt >> rate;
        for (int i = 0; i < cnt; i++)
            cin >> a[i];

        double t = (double)cnt * (double)rate / 100.0;
        sort(a, a + cnt);
        if (t > (double)(int)t)
            t++;
        if (rate == 0)
            cout << 100 << endl;
        else
            cout << a[cnt - (int)t] << endl;
    }
    return 0;
}
