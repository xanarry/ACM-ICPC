#include <iostream>
#include <set>
#include <map>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[])
{
    set<pair<int, int> > s;
    int n, x, y, r, c;
    cin >> n >> x >> y;
    while(n--)
    {
        cin >> r >> c;
        r -= x; c -= y;
        int g = gcd(r, c);
        r /= g; c /= g;
        s.insert(make_pair(r, c));
    }
    cout << s.size() << endl;
    return 0;
}
