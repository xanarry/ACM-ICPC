#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<string> dict;
    string a;
    while (getline(cin, a))
        dict.insert(a);

    for (auto x : dict)
    {
        for (int i = 1; i < x.length(); i++)
        {
            if (dict.count(x.substr(0, i)) && dict.count(x.substr(i, x.length() - i))) 
            {
                cout << x << endl;
                break;//one word may composed by more than one case, in case to output more than one time, need a break
            }
        }
    }
    return 0;
}

/*
a
ah
at
ahat
hat
*/