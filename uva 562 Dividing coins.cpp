/*
description
Download as PDF
It's commonly known that the Dutch have invented copper-wire. Two Dutch men were 
fighting over a nickel, which was made of copper. They were both so eager to get 
it and the fighting was so fierce, they stretched the coin to great length and 
thus created copper-wire.

Not commonly known is that the fighting started, after the two Dutch tried to 
divide a bag with coins between the two of them. The contents of the bag appeared 
not to be equally divisible. The Dutch of the past couldn't stand the fact that a 
division should favour one of them and they always wanted a fair share to the very 
last cent. Nowadays fighting over a single cent will not be seen anymore, but being 
capable of making an equal division as fair as possible is something that will 
remain important forever...

That's what this whole problem is about. Not everyone is capable of seeing instantly
what's the most fair division of a bag of coins between two persons. Your help is
asked to solve this problem.

Given a bag with a maximum of 100 coins, determine the most fair division between 
two persons. This means that the difference between the amount each person obtains 
should be minimised. The value of a coin varies from 1 cent to 500 cents. It's not 
allowed to split a single coin.

Input 
A line with the number of problems n, followed by n times:
a line with a non negative integer m (m <= 100) indicating the number of coins in the bag
a line with m numbers separated by one space, each number indicates the value of a coin.

Output 
The output consists of n lines. Each line contains the minimal positive difference between 
the amount the two persons obtain when they divide the coins from the corresponding bag.

Sample Input 
2
3
2 3 5
4
1 2 4 6

Sample Output 
0
1*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXM 100+5
#define MAX 25000+5
using namespace std;

int coin[MAXM];
int ans[MAX];
int main(const int argv, const char *args[])
{
    int n,m,sum;
    cin >> n;
    while(n--)
    {
        cin >> m;
        sum = 0;//所有硬币值总和
        for(int i = 0; i < m; i++) 
        {
            cin >> coin[i];
            sum += coin[i];
        }
        int N = sum / 2;//背包的最大容量
        memset(ans, 0, sizeof(ans));//初始化获取的价值是0

        for(int i = 0; i < m; i++)//对于m个银币
        {
            for(int j = N; j >= coin[i]; j--)
                ans[j] = max(ans[j], ans[j-coin[i]] + coin[i]);
        }
        cout << sum - 2*ans[N] << endl;
    }
    return 0;
}