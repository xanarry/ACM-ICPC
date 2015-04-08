/*
Description
为了纪念布鲁凯特诞生16周年
GP的公司举行了一个盛大的庆祝活动
在活动中,每个人都会在留言板上签下自己的名字留作纪念
在活动结束时,突然从人群中突然钻出来一个SB,但是他马上又消失了
为了消灭SB,我们必须先找到他
研究表明,正常人一定不会写错自己的名字,而SB则一定会写错自己的名字
现在给出在场所有人的名字,以及留言板上的所有名字
找出可能是SB的人
Input
输入包含多组数据.每组数据第一行包含一个整数n,表示有n个人
接下来n行为留言板上的n个名字
再接下来n行,为在场的n个人的名字
1<=n<=10000,每个名字的长度不大于200个字符
Output
对于每组数据,输出一行SB的名字。
Sample Input
3
Gaici Bier
Busi Qiao
Lanlan Lu
Busi Qiao
Bill Gates
Lanlan Lu
3
Nima Wang
SB
Ping Ge
Ping Ge
Nima Wang
Zhengen Jin
Sample Output
Bill Gates
Zhengen Jin
*/
#include <iostream>
#include <string>
#include <set>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string name;
    while (cin >> n)
    {
        getchar();
        set<string> nameset;
        for (int i = 0; i < n; i++)
        {
            getline(cin, name);
            nameset.insert(name);
        }
        string sb;
        for (int i = 0; i < n; i++)
        {
            getline(cin, name);
            if (!nameset.count(name))
                sb = name;
        }
        cout << sb << endl;
    }
    return 0;
}
