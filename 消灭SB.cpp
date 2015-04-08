/*
Description
现在,SB也找到了,奥特曼也找到了,奥特曼也没电了,姿势也找好了
终于到了消灭SB的时刻了
由于SB站在人群中,并且奥特曼光线只能横向发射或纵向发射
所以可能会伤及无辜
给出SB所在地区的人数分布地图
输出最少的被消灭的无辜的人的数量
Input
输入包含多组数据
每组数据第一行包含两个整数n和m,表示该区域为n*m的矩形
接下来有n行,每行m个字符,表示人数分布
对于第i行第j列的字符
如果是S,则表示这是有一个SB
如果是#,则表示这里是空地
如果是X,则表示这里有一个正常人
输入保证只有一个SB
1<=n,m<=5000
Output
对于每组数据,输出最小的被消灭的正常人的数量
Sample Input
3 3
#XX
#S#
XXX
Sample Output
0
*/#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char a[5001][5001];
int main(int argc, char const *argv[])
{
    int m, n;
    string input;
    ios::sync_with_stdio(false);
    while (cin >> m >> n)
    {
        int lx = 0, ly = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> input;
            for (int j = 0; j < n; j++)
            {
                a[i][j] = input[j];
                if ((a[i][j] - 'S') == 0)
                {
                    lx = i; 
                    ly = j;
                }
            }
        }
        int da = 0, db = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i][ly] - 'X' == 0)
                da++;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[lx][i] - 'X' == 0)
                db++;
        }
        cout << min(da, db) << endl;
    }
    return 0;
}