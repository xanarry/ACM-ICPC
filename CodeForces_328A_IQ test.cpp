/*
题意： 给4个数，判断是否为等差或等比数列（等比数列的定义与高中相同但是公比不能为1，
公比为1其实就是等差数列了。。）如果是等比或等差数列，输入其下一项，否则输入“42”。
如果下一项不是整数也输出“42”
*/
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double a[4];
    set<int> A;
    set<double> B;
    cin >> a[0];
    for (int i = 1; i < 4; i++)
    {
        cin >> a[i];
        A.insert(a[i] - a[i - 1]);
        if (a[i - 1]) 
            B.insert(a[i] / a[i - 1]);
    }

    if (A.size() == 1)
        cout << a[3] + *A.begin() << endl;
    else if (B.size() == 1)
    {
        double t = (double)a[3] * *B.begin();
        if (t - floor(t) == 0)
            cout << (int)t << endl;
        else
            cout << 42 << endl;
    }
    else
        cout << 42 << endl;
    return 0;
}