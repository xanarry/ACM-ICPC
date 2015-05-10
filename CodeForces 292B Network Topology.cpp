#include <iostream>
using namespace std;

int a[100010];
int main(int argc, char const *argv[])
{
    int n, m, u, v;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        a[u]++;
        a[v]++;
    }

    int c1 = 0, c2 = 0, cn = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1) 
            c1++;
        if (a[i] == 2) 
            c2++;
        if (a[i] == n - 1) 
            cn++;
    }

    if (c1 == 2 && c2 == n - 2) 
        cout << "bus topology" << endl;
    else if (c2 == n) 
        cout << "ring topology" << endl;
    else if (c1 == n - 1 && cn == 1) 
        cout << "star topology" << endl;
    else 
        cout << "unknown topology" << endl;
    return 0;
}