/*
将输入路径中的重叠‘/’处理为只保留一个，末尾不能有‘/’
input
///asdf////asdf/asdf////
////
output
/asdf/asdf/asdf
/
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string trim(string a)
{
    stringstream ss;
    char pre;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != '/')
        {
            ss << a[i];
            pre = a[i];
        }
        else if (a[i] == '/')
        {
            if (pre != '/')
            {
                ss << a[i];
                pre = a[i];
            }
        }
    }
    string r = ss.str();
    int len = r.length();
    if (len == 1)
        return r;
    else
        return r[len - 1] == '/' ? r.substr(0, len - 1) : r;
}


int main(int argc, char const *argv[])
{
    string a;
    while (cin >> a)
        cout << trim(a) << endl;
    return 0;
}