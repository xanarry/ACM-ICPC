#include <iostream>
using namespace std;

int t[1000010];
int main(int argc, char const *argv[])
{
    int l, m, a, b, ans = 0;
    cin >> l >> m;
    while (m--)
    {
        cin >> a >> b;
        t[a]++;
        t[b + 1]--;
    }

    for (int i = 1; i <= l; i++)
        t[i] += t[i - 1];
    
    for (int i = 0; i <= l; i++)
        if (t[i] == 0)
            ans++;

    cout << ans << endl;
    return 0;
}
