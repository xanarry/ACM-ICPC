/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19486
输入一系列天平的数据,判断天平是否平衡
*/
#include <iostream>
using namespace std;

bool flag;
int judge_fair()
{
    int w1, d1, w2, d2;
    cin >> w1 >> d1 >> w2 >> d2;
    if (!w1)
        w1 = judge_fair();
    if (!w2)
        w2 = judge_fair();

    if (w1 * d1 == w2 * d2)
        return w2 + w1;
    else
    {
        flag = false;
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    
    int t;
    cin >> t;
    while (t--)
    {
        flag = true;
        judge_fair();
        if (flag == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        if (t)
            cout << endl;
    }
    return 0;
}