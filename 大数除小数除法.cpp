/*
给定被除数整数a(a的范围是一个1位数到100位数之间的整数), 整数除数b(1<b<2^32), 输出a/b的整数部分
输入
8 3
输出
2
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string a;
    vector<int> v;
    int b, ia = 0;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
    {
        ia = ia * 10 + a[i] - '0';
        v.push_back(ia / b);
        ia = ia % b;
    }

    int start = 0;
    while (start < v.size())
    {
        if (v[start] != 0 || start == v.size())
            break;
        start++;
    }

    for (int i = start; i < v.size(); i++)
        cout << v[i];
    if (start == v.size())
        cout << 0;
    return 0;
}