//http://codeforces.com/contest/606/problem/C
#include <iostream>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;

int a[100005];
int main()
{
    int n, t;
    int len = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a[t] = a[t - 1] + 1;
        len = MAX(len, a[t]);
    }
    cout << n - len << endl;
    return 0;
}
/*
8
6 2 1 8 5 7 3 4
5

7
1 3 5 7 2 4 6
5
*/