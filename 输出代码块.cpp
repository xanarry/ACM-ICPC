/*
编程语言中的花括号是严格匹配的, 在一些编辑器中, 当选择到任意一个"{"或者"}"时, 编辑器都都会将这个花括号中的代码高亮起来以便阅读, 请写出一个能够识别代码片段的程序, 花括号中的内容保证不为空

输入
int main() {int a[]={1,2,3,4,5};}
12
输出
int a[]={1,2,3,4,5};

输入
{{{12}889980}}
2
输出
{12}889980
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    string code;
    vector<int> vl;
    map<int, int> pos;
    getline(cin, code);
    cin >> n;

    int bl = 0;
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '{')
        {
            pos[i] = i;
            vl.push_back(i);
        }
        if (code[i] == '}')
        {
            pos[i] = vl.back();
            vl.pop_back();
        }
        else if (i == n && vl.size() == 0)
            bl = 1;
    }

    int r = 1;
    if (bl)
        cout << "not in block" << endl;
    else
    {
        int start = 0;
        if (pos.count(n))
            start = pos[n];
        else
        {
            map<int, int>::iterator iterl, iteru;
            iteru = pos.upper_bound(n);
            iterl = iteru;
            iterl--;
            
            if (iteru->first == iteru->second && iterl->first == iterl->second)
                start = iterl->first;
            else if (iteru->first != iteru->second && iterl->first != iterl->second)
                start = iteru->second;
            else 
                start = iteru->second;
        }

        int l = 1;
        for (int i = start + 1; i < code.length(); i++)
        {
            if (code[i] == '{')
                l++;
            if (code[i] == '}')
                l--;
            if (l == 0)
                break;
            cout << code[i];
        }
    }
    return 0;
}