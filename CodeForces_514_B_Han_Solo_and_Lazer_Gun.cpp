/*
http://codeforces.com/problemset/problem/514/B
*/
#include <iostream>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 999999;
int main(int argc, char const *argv[])
{
    double n, cx, cy, x, y;
    set<double> slopes;
    cin >> n >> cx >> cy;
    while (n--)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        if (p.first == cx)
            slopes.insert(maxn);
        else
        {
            double t = (p.second - cy) / (p.first - cx);
            slopes.insert(t);
        }
    } 
    cout << slopes.size() << endl;
    return 0;
}