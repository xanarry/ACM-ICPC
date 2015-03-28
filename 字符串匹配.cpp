/*Description
给出一个字符串和多行文字，在这些文字中找到字符串出现的那些行。你的程序还需支持大小写敏感选项：
当选项打开时，表示同一个字母的大写和小写看作不同的字符；当选项关闭时，表示同一个字母的大写和
小写看作相同的字符。
Input
多组数据输入，对于每组数据，输入的第一行包含一个字符串S，由大小写英文字母组成。
　　第二行包含一个数字，表示大小写敏感的选项，当数字为0时表示大小写不敏感，当数字为1时表示大小写敏感。
　　第三行包含一个整数n，表示给出的文字的行数。
　　接下来n行，每行包含一个字符串，字符串由大小写英文字母组成，不含空格和其他字符。
Output
输出多行，每行包含一个字符串，按出现的顺序依次给出那些包含了字符串S的行，如果没有则输出 “No such string”。
Sample Input
Hello
1
5
HelloWorld
HiHiHelloHiHi
GrepIsAGreatTool
HELLO
HELLOisNOTHello
Sample Output
HelloWorld
HiHiHelloHiHi
HELLOisNOTHello
Hint
1<=n<=100，每个字符串的长度不超过100。
在上面的样例中，第四个字符串虽然也是Hello，但是大小写不正确。如果将输入的第二行改为0，则第四个字符串应该输出。
*/
#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    string R[100];
    int count1 = 0;
    string p;
    string sp;
    int c, n;
    cin >> p >> c >> n;
    sp = p;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        string ttt = t;
        if (t.find(p) != string::npos)
            R[count1++] = t;
        else if (c == 0)
        {
            for (int j = 0; j < t.length(); j++)
                t[j] = tolower(t[j]);
            for (int j = 0; j < p.length(); j++)
                sp[j] = tolower(p[j]);

            if (t.find(sp) != string::npos)
                R[count1++] = ttt;
        }
    }
    if (count1 == 0)
        cout << "No such string";
    else
    {
        for (int i = 0; i < count1 - 1; i++)
            cout << R[i] << endl;
        cout << R[count1 - 1];
    }
}

/*
Hello
0
5
HelloWorld
HiHiHelloHiHi
GrepIsAGreatTool
HELLO
HELLOisNOTHello
*/
