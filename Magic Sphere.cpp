//http://codeforces.com/contest/606/problem/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    int diff[3];
    diff[0] = a - x;
    diff[1] = b - y; 
    diff[2] = c - z;
    int ab = 0;
    int bl = 0;
    for (int i = 0; i < 3; i++)
        if (diff[i] >= 0)
            ab += diff[i] / 2;
        else
            bl -= diff[i];
    if (ab >= bl)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}