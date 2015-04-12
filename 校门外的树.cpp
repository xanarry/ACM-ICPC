/*
Description
某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴1的位置，另一端在L的位置；数轴上的每个整数点，即1，2，……，L，都种有一棵树。
由于学校要盖楼。所以要将一些比较高的树砍下来当木材。学校想知道砍下某些树之后，还剩下多少段连续树的数目。
比如马路的长度是5，那么1,2,3,4,5处各有一颗树。他们的高度分别是2,7,3,5,1。现在学校想砍掉最高的1颗树。那么，就会剩下2段树木，一段是从1开始到1结束的树，另一段是从3开始到5结束的树。
Input
多组数据输入
输入的第一行有两个整数L（1 <= L <= 10000）和 M（1 <= M <= 100），L代表马路的长度，M代表总共砍M次树，第二行包含L个不相同的正整数，为树木的高度h（0< h < 10^8）。第三行包含M个正整数k[i]，表示学校想砍掉最高的k[i]颗树(0 <k[i] < 100)。
Output
学校每次砍完树之后，输出剩下多少段树。用空格间隔。
Sample Input
5 2
2 7 3 5 1
1 1
Sample Output
2 3
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
struct Tree
{
    int loc, height;
    bool operator< (const Tree a) const
    {
        return height > a.height;
    }
};

int getseg(int *a, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        if (a[i] != 0 && (i - 1 < 0 || a[i - 1] == 0))
            sum++;
    return sum;
}

int a[10001];
int main()
{
    int l, m;
    while (cin >> l >> m)
    {
        vector<Tree> trees;
        for (int i = 0; i < l; i++)
        {
            cin >> a[i];
            Tree t;
            t.loc = i;
            t.height = a[i];
            trees.push_back(t);
        }
        sort(trees.begin(), trees.end());
        int t;
        stringstream ss;
        for (int i = 0; i < m; i++)
        {
            cin >> t;
            for (int j = 0; j < t; j++)
            {
                a[trees[0].loc] = 0;
                trees.erase(trees.begin());
            }
            ss << getseg(a, l) << " ";
        }
        cout << ss.str() << endl;
        ss.clear();
    }
    return 0;
}