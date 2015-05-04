/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19354
*/
#include <iostream>
#include <cstring>
using namespace std;

int rlt[1010];
int find_set(int x)
{
    if (rlt[x] == 0)
        return x;
    else
        return rlt[x] = find_set(rlt[x]);
}

int main(int argc, char const *argv[])
{
    int T;
    while (cin >> T)
    {
        while (T--)
        {
            int n, m, a, b, sum = 0;
            cin >> n >> m;
            memset(rlt, 0, sizeof(rlt));
            while (m--)
            {
                cin >> a >> b;
                if (find_set(a) != find_set(b))
                    rlt[find_set(b)] = find_set(a);
            }

            for (int i = 1; i <= n; i++)
                if (rlt[i] == 0)
                    sum++;
            cout << sum << endl;
        }
    }   
    return 0;
}   