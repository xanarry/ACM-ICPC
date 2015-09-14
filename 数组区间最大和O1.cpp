#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int len = 3;
    int a[len] = {-1,-5,2,6,-4,8,-5};
    int max = a[0];
    int curSum = a[0];
    int indexS = 0;
    int indexE = 1;
    int preS = 0;
    for (int i = 1; i < len; i++)
    {
        curSum = curSum + a[i];
        curSum = curSum > a[i] ? curSum : a[i];
        if (curSum > max)
        {
            max = curSum;
            indexE = i + 1;
            preS = indexS;
        }
        else
        {
            curSum = a[i];
            indexS = i + 1 < len - 1 ? i + 1 : i;
        }
    }
    cout << "max=" << max << " inverval=[" << preS << "," << indexE << ")" << endl;
    return 0;
}