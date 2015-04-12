/*
Description
给出一行字符串，仅包含英文字母和数字，如果为大写字母，则转换为小写字母，如果是小写字母则转换为大写字母，如果是数字则不作任何处理。
Input
输入包括若干行字符串(长度小于20)
Output
每行输出处理后的字符串。
Sample Input
abc123ABC
aaaabBBB
Sample Output
ABC123abc
AAAABbbb
*/
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
                str[i] = tolower(str[i]);
            else if (islower(str[i]))
                str[i] = toupper(str[i]);
        }
        cout << str << endl;
    }
    return 0;
}
