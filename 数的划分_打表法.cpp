/*
描述
将整数n分成k份，且每份不能为空，任意两份不能相同(不考虑顺序)。
例如：n=7，k=3，下面三种分法被认为是相同的。
1,1,5; 1,5,1; 5,1,1;
问有多少种不同的分法。

输入格式：
多组数据输入。输入n，k (6<n<=200，2<=k<=6)

输出格式：
一个整数，即不同的分法。

样例1
样例输入
7 3

样例输出
4*/
#include <iostream>
#include <cstring>
using namespace std;

bool isprime(int n);
int list[210][210];

void init()
{
    memset(list, 0, sizeof(list));
    for (int i = 1; i <=200; i++)
    {
        list[i][1] = 1;
        list[i][i] = 1;
    }
    for (int i = 3; i <= 200; i++)
        for (int j = 2; j <= i; j++)
            for (int k = 0; k <= j; k++)
                list[i][j] += list[i - j][k];
}
int main()
{
    int n, k;
    init();
    cin >> n >> k;
        cout << list[i][j] << endl;
    return 0;
}