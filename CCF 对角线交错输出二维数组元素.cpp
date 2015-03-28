#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[501][501];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i % 2 != 0)
                cout << a[i - 1 - j][j] << " ";
            else
                cout << a[j][i - 1 - j] << " ";
        }
    }
    for (int i = n, t = 1; i <= (n - 1) * 2; i++)
    {
        for (int j = t; j <= n - 1; j++)
        {
            if (i % 2 == 0)
                cout << a[i - j][j] << " ";
            else
                cout << a[j][i - j] << " ";
        }
        t++;
    }
    return 0;
}

/*
4
1 5 3 9
3 7 5 6
9 4 6 4
7 3 1 3
*/