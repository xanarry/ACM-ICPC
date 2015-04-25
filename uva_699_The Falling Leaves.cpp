/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19244
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1002;
int leaves[maxn] = {0};
int l, r, n;

void build(int pos)
{
    cin >> n;
    if (n == -1) return;
    leaves[pos] += n;
    build(pos - 1);
    build(pos + 1);
}

int main(int argc, char const *argv[])
{
    int ctr = 1, a;
    cin >> a;
    do
    {
        memset(leaves, 0, sizeof(leaves));
        int mid = maxn / 2;
        leaves[mid] = a;
        build(mid - 1); build(mid + 1);
        int s = 0;
        while (leaves[s] == 0)
            s++;
        cout << "Case " << ctr++ << ":\n" << leaves[s++];
        while (leaves[s] != 0) cout << " " << leaves[s++];
        cout << endl << endl;
        cin >> a;
    } while (a != -1);
    return 0;
}