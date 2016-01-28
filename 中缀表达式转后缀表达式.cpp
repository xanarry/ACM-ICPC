/*给一个只有加减乘除和数字的表达式, 输出其后缀表达式, 用空格隔开操作数和操作符

输入
2+3=
输出
2 3 + =

输入
2+3-2*3*5-11=
输出
2 3 + 2 3 * 5 * - 11 - =
输入
-1=
-1 =
*/

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

string a;
bool isoptr(int i)
{
    if (a[i] == '=' || a[i] == '*' || a[i] == '/' || a[i] == '+')
        return true;
    else if (a[i] == '-')
    {
        if (i == 0)
            return false;
        else if (a[i - 1] >= '0' && a[i - 1] <= '9')
            return true;
        else
            return false;
    }
    return false;
}

bool shouldout(char top, char cur)
{
    string opts = "+-*/=";
    int x = opts.find(top);
    int y = opts.find(cur);
    bool pri[][5] = {
        /*    +  -  *  /  = *///-->cur
        /*+*/{1, 1, 0, 0, 1},
        /*-*/{1, 1, 0, 0, 1},
        /***/{1, 1, 1, 1, 1},
        /*/*/{1, 1, 1, 1, 1}
    //-->top
    };
    return pri[x][y];
}

int main(int argc, char const *argv[])
{  
    cin >> a;
    stack<char> opts;
    int pre = 0, opt_pos = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (isoptr(i))
        {
            cout << atof(a.substr(pre, i - pre).c_str()) << " ";
            pre = i + 1;
        
            while (!opts.empty() && shouldout(opts.top(), a[i]))
            {
                cout << opts.top() << " ";
                opts.pop();
            }
            opts.push(a[i]);
        }
    }
    cout << "=" << endl;
    return 0;
}