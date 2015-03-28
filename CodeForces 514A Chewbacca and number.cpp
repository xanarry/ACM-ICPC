/*
输入一个数字1-10^18，将其中的的某些数字t换成9-t，使得最终构成的数字最小，并且不能有前缀0
第一位是9的话不管
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    char n[100];
    cin >> n;
    for (int i = 0; i < strlen(n); i++)
    {
        if (n[i] - '0' > 4 && (n[i] != '9' || i != 0))
            n[i] = 9 - (n[i] - '0') + '0';
    }
    int i = 0;
    for (; i < strlen(n) - 1 && n[i] == '0'; i++);
    cout << n + i << endl;
    return 0;
}