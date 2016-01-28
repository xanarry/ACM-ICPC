/*给定一个m*n的矩阵, (1<=m<=100, 1<=n<=100)和要求旋转的度数d, d大于0且是90度的倍数, 输出旋转后的矩阵, 先右旋转是正方向
第一行输入m,n,d
接下来m行, 每行n个数输入这个矩阵
输入
2 3 270
1 2 3
4 5 6
3 6
2 5
1 4
*/
#include <iostream>
using namespace std;

int m, n, d;
int a[105][105];

void r0()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void r90()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
            cout << a[j][i] << " ";
        cout << endl;
    }
}

void r180()
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void r270()
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
            cout << a[j][i] << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin >> m >> n >> d;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    switch ((d / 90) % 4)
    {
        case 0: r0(); break;
        case 1: r90(); break;
        case 2: r180(); break;
        case 3: r270(); break;
    }
    return 0;
}