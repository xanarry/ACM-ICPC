/*
描述
xuzhenyi到大同水果店去买水果，但老板huyichen告诉他每次只能买一种，
但是xuzhenyi想吃两种，于是在讨价还价之后，huyichen说只要xuzhenyi
能把他想要的两种水果合并成一种，就能成功。你能帮他吗？
输入格式
多组数据输入。输入文件包含两个要组合的水果名字。所有的名字最多有100个字母。(有若干行）
输出格式
对每一组测试数据，打印出一个最短的组合长度.
样例
样例输入
apple peach
ananas banana
pear peach
样例输出
8
7
6
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using  namespace std;

int LCS(string a, string b)//寻找最长公共子序列长度
{
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++)
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return dp[a.length()][b.length()];
}

int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a >> b)
        cout << a.length() + b.length() - LCS(a, b) << endl;
    return 0;
}