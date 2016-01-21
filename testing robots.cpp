//http://codeforces.com/contest/606/problem/B
#include <iostream>
#include <string>
using namespace std;

int a[505][505] = {0};
int main(int argc, char const *argv[])
{
    int x, y, x0, y0;
    string cmd;
    cin >> x >> y >> x0 >> y0;
    cin >> cmd;
    int bf = 1;
    cout << "1 ";
    a[x0][y0] = 1;
    for (int i = 0; i < cmd.length() - 1; i++)
    {
        switch(cmd[i])
        {
            case 'U':
                if (x0 > 1)
                {
                    x0--;
                    if (a[x0][y0] == 0)
                    { 
                        cout << "1 ";
                        bf++;
                        a[x0][y0] = 1;
                    }
                    else
                        cout << "0 ";
                }
                else
                    cout << "0 ";
            break;
            case 'D':
                if (x0 < x)
                {
                    x0++;
                    if (a[x0][y0] == 0)
                    {
                        cout << "1 ";
                        bf++;
                        a[x0][y0] = 1;
                    }
                    else
                        cout << "0 ";
                }
                else
                    cout << "0 ";
            break;
            case 'L':
                if (y0 > 1)
                {
                    y0--;
                    if (a[x0][y0] == 0)
                    {
                        cout << "1 ";
                        bf++;
                        a[x0][y0] = 1;
                    }
                    else
                        cout << "0 ";
                }
                else
                    cout << "0 ";
            break;
            case 'R':
                if (y0 < y)
                {
                    y0++;
                    if (a[x0][y0] == 0)
                    {
                        cout << "1 ";
                        bf++;
                        a[x0][y0] = 1;
                    }
                    else
                        cout << "0 ";
                }
                else
                    cout << "0 ";
            break;
        }
    }
    cout << x * y - bf << endl;
    return 0;
}