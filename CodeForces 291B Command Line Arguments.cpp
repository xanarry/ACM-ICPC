#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> v;
    string a;
    getline(cin, a);
    bool even = true;
    int pre = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '\"')
        {
            if (even)
            {
                a[i] = '<';
                pre = i;
                even = false;
            }
            else
            {
                a[i] = '>';
                even = true;
                for (int j = pre; j < i; j++)
                    if (a[j] == ' ')
                        a[j] = '`';
            }
        }
    }
    a += " ";
    int s = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == ' ')
        {
            string t = a.substr(s, i - s);
            for (int j = 0; j < t.length(); j++)
                if (t[j] == '`')
                    t[j] = ' ';
            if (t.length() > 0 && t != " ")
            {
                if (t[0] != '<')
                    t = "<" + t + ">";
                v.push_back(t);
            }
            s = i + 1;
        }
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}