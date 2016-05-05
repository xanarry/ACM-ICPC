#include <iostream>
#include <algorithm>
using namespace std;

struct Stn
{
    int x, y, len, vo;
    Stn(){}
    void gl()
    {
        len = x * x + y * y;
    }

    bool operator< (const Stn a) const
    {
        if (len != a.len)
            return len < a.len;
        else
            return vo > a.vo;
    }
};

Stn ary[1005];
int main(int argc, char const *argv[])
{
    int n, v;
    while (cin >> n >> v)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> ary[i].x >> ary[i].y >> ary[i].vo;
            ary[i].gl();
        }
        sort(ary, ary + n);
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n && cnt < v; i++)
        {
            cnt += ary[i].vo;
            ans++;
        }
        if (cnt < v)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

/*
3 67
1 1 37
2 2 5
-2 -2 68
3 68
1 1 34
2 2 5
-2 -2 16
*/