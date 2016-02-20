#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Block
{
    int a, b, h;
    bool operator< (const Block o) const
    {
        if (a != o.a)
            return a < o.a;
        else
            return b < o.b;
    }

    Block(int x, int y, int z)
    {
        a = x;
        b = y;
        h = z;
    }
    Block(){}
};

Block m[1000];
int dp[1000];

int main(int argc, char const *argv[])
{
    int n, a, b, c, index;
    int cnt = 0;
    int ma = 0x7fffff, mb = 0x7fffff;
    while (cin >> n && n)
    {
        index = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            //对于矩形, a*b和b*a是一致的, 所以对a,b排序
            m[index++] = Block(max(a, b), min(a, b), c);
            m[index++] = Block(max(c, b), min(c, b), a);
            m[index++] = Block(max(c, a), min(c, a), b);

        }

        //排序, 找到起点
        sort(m, m + index);
        for (int i = 0; i < index; i++)
            dp[i] = m[i].h;

        int ans = 0;
        //DAG上的动态规划
        for (int i = index - 1; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                if (m[i].a > m[j].a && m[i].b > m[j].b)
                {
                    dp[j] = max(dp[j], dp[i] + m[j].h);
                    ans = max(ans, dp[j]);
                }
            }
        }
        cout << "Case " << ++cnt << ": maximum height = " << ans << endl;
    }
    return 0;
}

/*
1
10 20 30

2
6 8 10
5 5 5

7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7

5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27

0
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342

*/