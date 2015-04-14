/*
Description
马上参加ACM省赛了，一个队伍的小伙伴因为队伍的名字争论不休，每个人都认为自己的队伍名字更好。
所以硕硕想出了一个好办法，扔骰子。谁的点数最大，就用谁的队伍名字。
他们俩人都扔出了自己的骰子，硕硕想知道，自己的胜率是多大。如果硕硕和别人的点数相同，且都是
最大，那么就用硕硕的。
P.S.骰子是正常的6面骰子......
Input
多组数据输入，每组数据一行，两个正整数a,b。表示其他两人扔出的骰子点数。
Output
硕硕的胜率，用分数表示，化到最简.
如果胜率为0，输出0/1
如果胜率为100%，输出1/1
Sample Input
4 2
Sample Output
1/2
*/
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int m, int n)
{
    int t;
    while (t = m % n)
    {
        m = n;
        n = t;
    }
    return n;
}

int main(int argc, char const *argv[])
{
    int a, b, g;
    while (cin >> a >> b)
    {
        int t = 6 - max(a ,b) + 1;
        g = gcd(t, 6);
        cout << t / g << "/" << 6 / g << endl;
    }
    return 0;
}