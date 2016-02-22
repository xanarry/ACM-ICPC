#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b, c;
    int i, j, t, k;
    cin >> t;
    int d[1000];
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> a >> b >> c;
        memset(d, 0, sizeof(d));
        for (k = 0, i = 0, j = 0; k < c.length(); k++)
        {
            for (int x = 0; x < k; x++)//对于c串中的每个新字符,检查前面已经存在的字符匹配次数是否有两次
            {
                if (c[k] == c[x] && d[x] > 1)
                {
                    d[k]++;//如果有两次则将前面能同时从a,b串匹配的字符串中移一个过来
                    d[x]--;
                }
            }
            //检查是否能从a匹配
            if (a[i] == c[k])
            {
                d[k]++;
                i++;
            }
            //检查是否能从b匹配
            if (b[j] == c[k])
            {
                d[k]++;
                j++;
            }
            if (d[k] == 0)//如果对于某个字符无法匹配, 那么就已经确定不能由a,b构成
                break;
        }   

        if (k == c.length())
            cout << "Data set " << kase << ": yes" << endl;
        else
            cout << "Data set " << kase << ": no" << endl;
    }
    return 0;
}

/*
4
cat tree tcraete
cat tree catrtee
cat tree cttaree
about abdovaza abdovazaabout
*/