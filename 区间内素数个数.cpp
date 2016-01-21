#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {   
        int j = 2;
        for (; j <= sqrt(i); j++)
            if (i % j == 0)
                break;
        if (j > sqrt(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}