/*
给定n组数据，对于每组数据，输入人的个数和要求的及格率，然后输出每个人的分数，
要求如果要满足给定的及格率，应该将及格分数线定为多少，输出这个分数
sample input
2
4 60
12 23 43 13
5 70
67 45 87 34 89
sample output
13
45
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a, b;
    int scr[110];
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < a; j++)
            cin >> scr[j];
        sort(scr, scr + a);

        if (b == 0)
        {
            cout << 100 << endl;
            continue;
        }
        double t = (double)a * (double)b / 100.0;

        if (t > floor(t))
            t++;
        cout << scr[a - (int)t] << endl;
    }
    return 0;
}
