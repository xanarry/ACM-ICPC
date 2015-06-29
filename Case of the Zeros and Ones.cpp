#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int ch[200005];
int main(int argc, char const *argv[])
{
    int n;
    int z = 0;
    int o = 0;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        char t = getchar();
        if (t == '0')
            z++;
        if (t == '1')
            o++;
        ch[i] = t;
    }
    int dif = z - o;
    cout << (dif >= 0 ? dif : -dif) << endl;
    return 0;
}