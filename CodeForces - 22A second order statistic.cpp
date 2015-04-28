/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=24952
*/
#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        s.insert(t);
    }
    if (s.size() == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    int pre = *s.begin();
    int cur = *++s.begin();
    if (pre < cur)
        cout << cur << endl;
    else
        cout << "NO" << endl;
    return 0;
}