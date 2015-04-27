/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=20793
给一系列数字,其中有一个奇偶性与其他数不同的数,输出这个数的位置
将奇偶性数转换为01字符串,查找单独0或者1所在的位置
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        string a = "";
        int odd = 0, even = 0, t;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            if (t % 2 == 0)
            {
                even++;
                a += "1";
            }
            else
            {
                odd++;
                a += "0";
            }
        }
        cout << a.find(odd == 1 ? "0" : "1") + 1 << endl;
    }
    return 0;
}