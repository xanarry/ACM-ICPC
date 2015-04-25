#include <iostream>
using namespace std;

const int maxn = 100;
int r, c;
int a[maxn + 5][maxn + 5];

void dfs(int x, int y)
{
    if (x < 0 || x >= r || y < 0 || y >= c)
        return;
    if (a[x][y] == '@')
        a[x][y] = '*';
    else
        return;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i != 0 || j != 0)
                dfs(x + i, y + j);
}

int main(int argc, char const *argv[])
{
    string str;
    while (cin >> r >> c && r != 0 && c != 0)
    {
        for (int i = 0; i < r; i++)
        {
            cin >> str;
            for (int j = 0; j < c; j++)
                a[i][j] = str[j];
        }

        int blocks = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (a[i][j] == '@')
                {
                    blocks++;
                    dfs(i, j);
                }
        cout << blocks << endl;
    }
    return 0;
}

/*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
*/
