#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, int> ids;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        if (id == 0)
            continue;
        if (!ids.count(id))
            ids[id] = 1;
        else
            ids[id]++;
    }

    for (map<int, int>::iterator iter = ids.begin(); iter != ids.end(); ++iter)
    {
        if (iter->second == 2)
            sum++;
        else if (iter->second > 2)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << sum << endl;
    return 0;
}