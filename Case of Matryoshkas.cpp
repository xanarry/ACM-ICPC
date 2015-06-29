#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k, m;
    cin >> n >> k;
    map<int, vector<int> > input;
    int flag;
    for (int i = 0; i < k; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            if (t == 1)
                flag = i;
            input[i].push_back(t);
        }
    }

    int bi = 1;
    for (; bi < input[flag].size(); bi++)
        if (input[flag][bi] - input[flag][bi - 1] != 1)
            break;

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (i == flag)
            ans += (input[flag].size() - bi) * 2;
        else   
            ans += (input[i].size() - 1) * 2;
    }
    ans += (k - 1);
    cout << ans << endl;
    return 0;
}
