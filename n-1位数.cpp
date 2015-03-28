/*
给出一个数字，输出删除第一位后的结构，去除删除后数字的前缀0，如果删除后全为
0，那么直接输出0
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string n;
    while (cin >> n)
    {
        int i = 1;
        for (; i < n.length(); i++)
        {
            if (n[i] != '0')
                break;
        }
        if (i == n.length())
            cout << 0 << endl;
        else
            cout << n.substr(i) << endl;
    }
    return 0;
}