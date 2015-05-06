/*
Description
东仙队长要种庄稼,但是美国支援的金坷垃已经用完了
于是东仙队长需要再去购买一些
美国在非洲开设了N家金坷垃专卖店
第i家店的初始单价为pi,储量为ti
由于金坷垃十分稀有,所以每家店在每售出一袋后,都会把价格提高一倍
现在东仙队长有M块钱,问最多能买到多少袋金坷垃
Input
输入包含多组数据.每组数据第一行包含两个整数n和m,表示n家金坷垃专卖店和m块钱
接下来有n行,每行包含两个整数pi和ti,表示金坷垃的单价和储量
1<=n<=10^6
1<=m<=10^9
1<=pi,ti<=10^3
Output
对于每组数据,输出一行,包含一个整数,表示最多能购买的金坷垃的数量
Sample Input
5 100
5 3
1 5
8 6
7 5
9 5
Sample Output
12
*/
#include <iostream>
#include <queue>
using namespace std;

struct SP
{
    int price, num; 
    bool operator< (const SP a) const
    {
        return price > a.price;
    } 
};

int main(int argc, char const *argv[])
{
    int n, maxp;
    while (cin >> n >> maxp)
    {
        priority_queue<SP> pcs;
        for (int i = 0; i < n; i++)
        {
            SP p;
            cin >> p.price >> p.num;
            pcs.push(p);
        }

        int counter = 0;
        while (maxp >= pcs.top().price)
        {
            SP p = pcs.top();
            pcs.pop();
            maxp -= p.price;
            if (p.num > 1)
            {
                p.price *= 2;
                p.num--;
                pcs.push(p);
            }
            counter++;
        } 
        cout << counter << endl;
    }
    return 0;
}
/*
input
5 100
5 3
1 5
8 6
7 5
9 5

output
12
*/