/*
Description
找到SB之后,我们就要消灭他
为了使用奥特曼必杀光线来消灭SB
我们需要把奥特曼请过来
虽说众所周知,奥特曼居住在M78星云
但是最近宇宙局势动荡,经常出现一个星球吞并另一个星球的情况
如果M99星云吞并了M78星云,那么我们就得去M99星云找奥特曼了
再如果M99星云被火星吞并了,那么我们就要去火星找奥特曼
现在你从界王那的到了一个星球吞并列表
列表中给出了所有星球吞并的情况
但是由于界王记性不好,经常忘记某个星球已经被吞并了
于是列表中会出现这种情况
A星球吞并了B星球
A星球吞并了C星球
B星球吞并了D星球
D星球吞并了E星球
F星球吞并了E星球
其中第三条,第四条和第五条明显是不对的
对于这三条信息,界王想表达的是
A星球吞并了D星球
A星球吞并了E星球
F星球吞并了A星球
你需要根据列表给出的信息,确定奥特曼的位置
Input
输入包含多组数据.每组数据第一行包含一个整数m,表示列表中有m条信息
接下来m行,每行两个用空格分开的字符串a和b,表示a吞并了b
每个字符串的长度不大于200
1<=m<=10000
如果有矛盾的信息,请忽略
Output
对于每组数据,输出奥特曼所在的星球
Sample Input
5
MARS M99
M99 M78
SUN MARS
M66 M99
M78 EARTH
2
EARTH MARS
MARS SUN
Sample Output
M66
M78
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

string findset(map<string, string> cp, string c)
{
    if (cp[c].size())
        return cp[c] = findset(cp, cp[c]);
    else
        return c;
}

int main(int argc, char const *argv[])
{
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        string p, c, a, b;
        map<string, string> cp;

        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            string pa = findset(cp, a);
            string pb = findset(cp, b);
            if (pa != pb);
                cp[pb] = pa;
        }
        cout << findset(cp, "M78");
    }
    return 0;
}
