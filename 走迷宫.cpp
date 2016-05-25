#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool reachable = false;
int sx, sy, dx, dy, k;
char a[104][104];

void dfs(int sx, int sy)
{
    if (a[sx][sy] == '.')
    {
        if (sx == dx && sy == dy)
        {
            reachable = true;
            return;
        }
        a[sx][sy] = '#';
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if (abs(i) != abs(j) && sx + i >= 0 && sy + j >= 0 && sx + i < k && sy + j < k)
                    dfs(sx + i, sy + j);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        reachable = false;
        cin >> k;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                cin >> a[i][j];

        cin >> sx >> sy >> dx >> dy;
        string d = "";
        dfs(sx, sy);
        cout << (reachable ? "YES" : "NO") << endl;
    }
    return 0;
}
/*
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
*/