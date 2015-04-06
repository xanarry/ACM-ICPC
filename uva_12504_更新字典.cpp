/*http://uva.onlinejudge.org/external/125/12504.pdf
12504 Updating a Dictionary
In this problem, a dictionary is collection of key-value pairs, where keys are lower-case letters, and
values are non-negative integers. Given an old dictionary and a new dictionary, find out what were
changed.
Each dictionary is formatting as follows:
{key:value,key:value,...,key:value}
Each key is a string of lower-case letters, and each value is a non-negative integer without leading
zeros or prefix ‘+’. (i.e. -4, 03 and +77 are illegal). Each key will appear at most once, but keys can
appear in any order.
Input
The first line contains the number of test cases T (T ≤ 1000). Each test case contains two lines. The
first line contains the old dictionary, and the second line contains the new dictionary. Each line will
contain at most 100 characters and will not contain any whitespace characters. Both dictionaries could
be empty.
WARNING: there are no restrictions on the lengths of each key and value in the dictionary. That
means keys could be really long and values could be really large.
Output
For each test case, print the changes, formatted as follows:
• First, if there are any new keys, print ‘+’ and then the new keys in increasing order (lexicographically),
separated by commas.
• Second, if there are any removed keys, print ‘-’ and then the removed keys in increasing order
(lexicographically), separated by commas.
• Last, if there are any keys with changed value, print ‘*’ and then these keys in increasing order
(lexicographically), separated by commas.
If the two dictionaries are identical, print ‘No changes’ (without quotes) instead.
Print a blank line after each test case.
Sample Input
3
{a:3,b:4,c:10,f:6}
{a:3,c:5,d:10,ee:4}
{x:1,xyz:123456789123456789123456789}
{xyz:123456789123456789123456789,x:1}
{first:1,second:2,third:3}
{third:3,second:2}
niversidad de Valladolid OJ: 12504 – Updating a Dictionary 2/2
Sample Output
+d,ee
-b,f
*c
No changes
-first
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    string a, b, key, val;
    int n;
    cin >> n;
    while (n--)
    {
        string add = "+", del = "-", mod = "*";
        cin >> a >> b;
        map<string, string> mpa, mpb;
        if (a.length() > 2) 
        {
            for (int i = 1, sp = 1; i < a.length(); i++)
            {
                if (a[i] == ':')
                {
                    key = a.substr(sp, i - sp);
                    sp = i + 1;
                }
                if (a[i] == ',' || a[i] == '}')
                {
                    val = a.substr(sp, i - sp);
                    sp = i + 1;
                    mpa[key] = val;
                }
            }
        }

        if (b.length() > 2) 
        {
            for (int i = 1, sp = 1; i < b.length(); i++)
            {
                if (b[i] == ':')
                {
                    key = b.substr(sp, i - sp);
                    sp = i + 1;
                }
                if (b[i] == ',' || b[i] == '}')
                {
                    val = b.substr(sp, i - sp);
                    sp = i + 1;
                    mpb[key] = val;
                }
            }
        }

        for (map<string, string>::iterator iter = mpb.begin(); iter != mpb.end(); ++iter)
        {
            if (!mpa.count(iter->first))//input key is not in the map means add
                add += iter->first + ",";  
            else if (mpa[iter->first] != mpb[iter->first])//if the value has changed
                mod += iter->first + ",";
        }

        for (map<string, string>::iterator iter = mpa.begin(); iter != mpa.end(); ++iter)
            if (!mpb.count(iter->first))
                del += iter->first + ",";

        add = add.substr(0, add.length() - 1);
        del = del.substr(0, del.length() - 1);
        mod = mod.substr(0, mod.length() - 1);
        string r[3] = {add, del, mod};
        bool nochange = true;
        for (int i = 0; i < 3; i++)
        {
            if (r[i].length() != 0)
            {
                cout << r[i] << endl;
                nochange = false;
            }
        }
        if (nochange)
            cout << "No changes" << endl;
        cout << endl;
    }
    return 0;
}