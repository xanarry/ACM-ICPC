/*
Description
又到了一年一度的金坷垃祭
今年威廉伯爵打算在最显眼的地方拉出写着"JINKELA"的条幅
于是就派人去制作这个条幅
不幸的是,由于打印机故障,最终打印出来的条幅上写的并不是"JINKELA",而是一些随机的大写字母
而且已经没有时间了,必须马上把条幅拉出去
于是威廉伯爵打算通过涂抹掉一些字符,使得最后剩下的字符是"JINKELA"
Input
输入包含多组数据.每组数据占一行,包含一个字符串s,表示打印出来的条幅上的文字
1<=LEN(s)<=200
Output
对于每组数据,如果威廉伯爵可以成功得到"JINKELA",输出"YES",否则输出"NO"
Sample Input
XJIDDNFKDEGLSAUYI
JQINQKQEQAWLIYUIE
ABCDEFG
JINKELA
Sample Output
YES
NO
NO
YES
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string n;
    const string pgd = "JINKELA";
    while (cin >> n)
    {
        int i = 0, j = 0;
        while (i < pgd.length())
        {
            while (j < n.length())
            {
                if (n[j] == pgd[i])
                {
                    i++;
                    break;
                }
                j++;
            }
            if (j == n.length())
                break;
        }
        if (i == pgd.length())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}