/*
Description
东仙队长买够了金坷垃后就要开始种小麦了
田地是n*m的矩形区域
为了能让小麦亩产一千八,自然要使用金坷垃
由于金坷垃的特殊性,每块地不能被播撒一次以上的肥料,否则就会导致减产
每袋金坷垃需要和肥料混合后放在一个特殊的施肥机器里
这个施肥机器每次可以播撒k*k单位面积,所以可能会导致浪费(播撒到田地范围之外)
于是请你求出最少需要播撒的次数
Input
输入包含多组数据.每组数据占一行,包含三个整数n,m,k
1<=n,m,k<=10^10
Output
对于每组数据输出占一行,包含一个整数,表示最少播撒的次数
Sample Input
5 7 2
Sample Output
12
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, k;B
    while (cin >> n >> m >> k)
    {
        if (n % k != 0)
            n += n % k;
        if (m % k != 0)
            m += m % k;
        cout << m * n / k / k << endl;
    }
    return 0;
}