#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int len = 7;
    int a[len] = {3, -8, -7, 9, 12, 7, 5};
    int max = 0x80000000;
    int indexS = 0;
    int indexE = 0;
    for (int i = 0; i < len; i++)
    {
        int sum = 0;
        for (int j = i; j < len; j++)
        {
            sum += a[j];
            if (sum > max)
            {
                max = sum;
                indexS = i;
                indexE = j;
            }
        }
    }
    cout << "max=" << max << " inverval=[" << indexS << "," << indexE << "]" << endl;
    return 0;
}