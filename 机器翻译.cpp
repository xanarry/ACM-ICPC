/*http://qdacm.openjudge.cn/day20151115/1/*/
#include <iostream>
#include <queue>
using namespace std;

bool find(queue<int> tmem, int w)
{
    while (!tmem.empty())
    {
        int temp = tmem.front();
        tmem.pop();
        if (temp == w)
            return true;
    }
    return false;
}

int main()
{
    int m, n, w;
    int ans = 0;
    queue<int> tmem;
    cin >> m >> n;
    while (n--)
    {
        cin >> w;
        if (!find(tmem, w))
        {
            if (tmem.size() >= m)
                tmem.pop();
            tmem.push(w);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}