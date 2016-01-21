#include <iostream>
using namespace std;

bool bolb[100] = {false};

int main(int argc, char const *argv[])
{
    int n, m, t, a, i;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> a;
            bolb[a] = true;
        }
    }
    for (i = 1; i <= m; i++)
        if (!bolb[i])
            break;
    if (i > m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}