/*描述
有n个球，从外表上看不出差别，但有一个球比其他球重，其他N-1个球质量相等。请问：在地球上（MS废话），用天平最少称几次可以称出来？

输入格式：
多组数据输入。一个自然数N(0<N<=2^24)

输出格式：
输出用天平最小的称量数m(m<30000)
样例
样例输入
8

样例输出
2*/
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;

    while (cin >> n)
    {
        int i = 1;
        int t = 3;//即ceil(log(n)/log(3))
        if (n > 3)
            while (i++)
                if (n <= pow(3, i))
                    break;
        cout << i << endl;
    }
    return 0;
}