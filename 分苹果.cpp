#include <iostream>
using namespace std;

bool split(int tSum, int tn)
{
    int i = 0;
    for (; i < tn && tSum % tn == 1; i++)
        tSum = tSum - tSum / tn - 1;
    if (tSum % tn == 0 && i == tn)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int n, i = 10;
    cin >> n;
    while (i++)//无限循环, 直到找到一个满足要求的数
    {
        if (split(i, n))
        {
            cout << n << " -> " << i << endl;
            break;
        }
    }
    return 0;
}