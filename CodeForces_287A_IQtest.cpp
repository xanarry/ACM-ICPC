/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=37850
*/
#include <iostream>
#include <string>
using namespace std;

char a[4][4];
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < 4; j++)
            a[i][j] = in[j];
    }

    bool flag = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)//枚举4x4中的每个2x2的矩形
        {
            int ca = 0, cb = 0;
            for (int k = i; k < i + 2; k++)//遍历每个2x2的矩形
            {
                for (int l = j; l < j + 2; l++)
                {
                    if (a[k][l] == '#')标记个数
                        ca++;
                    else if (a[k][l] == '.')
                        cb++;
                }
            }
            if (ca >= 3 || cb >= 3)//满足条件
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}