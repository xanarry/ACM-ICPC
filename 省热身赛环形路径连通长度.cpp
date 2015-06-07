/*
题目描述:
    给定n个点编号1-n,按顺序依次围成一个圆圈,输入两个点,求最少要用多少条线将这两个点连接起来
    多组输入
*/
#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, sum = 0;
        cin >> u >> v;
        if (v > u)
        {
            if ((double)(v - u) <= (double)(n / 2))
                sum = v - u;
            else 
                sum = n - (v - u);
        }
        else
        {
            if ((double)(u - v) > (double)(n / 2))
                sum = n - (u - v);
            else
                sum = u - v;
        }
        cout << sum << endl;
    }
    return 0;
}
