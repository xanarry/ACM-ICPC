/*Description
有一天，一位黑黑的骑士要去一座没有楼梯的埃菲尔铁塔，救他心爱的丧尸公主。
为了救他心爱的公主，他必须找到7颗龙珠，召唤神龙。
什么乱七八糟的，不编了。
他的面前有n条路，每条路上有k[i]个宠物可以选择。他将随机获得一个。当然，
他走每条路的概率也是相同的。只有一只宠物，才能让他“升职加薪，当上总经理，
出任CEO，迎娶白富美，走上人生巅峰”。求他获得这只宠物的概率。
Input
多组数据输入，对于每组数据有两行，第一行一个正整数n，第二行包含n个正整数k[i]。
( 1 <= n <= 100 ; 1 <= k[i] <= 100)
Output
对于每组数据，每行输出一个浮点数，精确到小数点后4位。.
Sample Input
3
5 8 7
Sample Output
0.0500*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            double t;
            cin >> t;
            sum += t;
        }
        printf("%.4f\n", 1 / sum);
    }
    return 0;
}