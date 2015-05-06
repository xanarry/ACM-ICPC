/*
Description
威廉伯爵某天兴致大开,打算亲自去算算今天的账目--卖了多少金坷垃
但不幸的是,他的计算器的键盘坏掉了,10个数字中,只剩下0和1是好使的
于是为了录入一个数字,威廉伯爵必须写成若干个由0和1组成的数字的相加的形式
比如威廉伯爵想输入3546,则需要这样输入
1111+1111+1111+111+101+1
当然,也存在其他的方式,比如用3546个1相加
但是很显然,上面的方式是按键次数最少的,24次
现在,对于每个需要输入的数字,威廉伯爵都想知道需要按键的最少次数
Input
输入包含多组数据.每组数据占一行,包含一个整数n,表示威廉伯爵想输入的数字
0<=n<=10^9
Output
对于每组数据,输出一行,包含一个整数,表示需要按键的最少次数
Sample Input
3546
Sample Output
24
*/
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int n[9][9];
int main(int argc, char const *argv[])
{
    string a;
    while (cin >> a)
    {
        memset(n, 0, sizeof(n));
        int maxn = -1;
        for (int i = 0; i < a.length(); i++)
        {
            int t = a[i] - '0';
            if (t > maxn)
                maxn = t;
            for (int j = 0; j < t; j++)
                n[j][i] = 1;
        }
        
        int total = 0;
        for (int i = 0; i < maxn; i++)
        {
            stringstream ss;
            int j = 0;
            while (n[i][j] == 0)
                j++;
            while (j < a.length())
                ss << n[i][j++];
            total += ss.str().length();
        }
        if (maxn > 0)
            total += maxn - 1;
        cout << total << endl;
    }
    return 0;
}
