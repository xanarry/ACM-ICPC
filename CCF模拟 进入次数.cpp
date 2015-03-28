/*
进入次数
有任意用户每天进出图书馆，用数字编号用户,输入一系列用户的编号，判断他是第几次进出图书馆
输入
第一行一个n，表示用户个数
第二行，输入n个用户编号
输出
一行，输出每个用户当前的进入次数
样例
input：
5
1 2 1 3 2
output：
1 2 1 1 2
*/
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    map<int, int> m;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (m.count(a)) { m[a]++; cout << m[a] << " ";}
        else { m[a] = 1; cout << m[a] << " ";}
    }
    return 0;
}