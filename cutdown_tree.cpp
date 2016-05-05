#include <iostream>
#include <algorithm>
using namespace std;

int x[4];
int y[4];
//计算两个矩形交叉部分面积
int main(int argc, char const *argv[])
{
    int n, m;
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1]; //输入第一个矩形的对角顶点
        cin >> x[2] >> y[2] >> x[3] >> y[3]; //输入第二个矩形的对角顶点

        if (x[1] < x[2] || x[3] < x[0] || y[1] < y[2] || y[3] < y[0])
            cout << 0 << endl;
        else
        {
            sort(x, x + 4);
            sort(y, y + 4);
            cout << (x[2] - x[1] + 1) * (y[2] - y[1] + 1) << endl;
        }
    }
    return 0;
}