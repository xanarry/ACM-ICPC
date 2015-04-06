//http://codeforces.com/problemset/problem/519/A
#include <iostream>
#include <cctype>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    char a[8][8];
    map<char, int> val;
    val['q'] = 9;
    val['r'] = 5;
    val['b'] = 3;
    val['n'] = 3;
    val['p'] = 1;
    int w = 0;
    int b = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
            if (a[i][j] - '.' != 0 && a[i][j] -'k' != 0)
            {
                if (isupper(a[i][j]))
                {
                    w += val[tolower(a[i][j])];
                }
                else
                    b += val[tolower(a[i][j])];
            }
        }
    }
    if (w > b)
        cout << "White" << endl;
    else if (w < b)
        cout << "Black" << endl;
    else
        cout << "Draw" << endl; 
    return 0;
}