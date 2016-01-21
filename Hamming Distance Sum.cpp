//http://codeforces.com/contest/608/problem/B
#include <cstdio>
#include <cstring>
using namespace std;

char a[200005];
char b[200005];
long s[2][200005];
int main(int argc, char const *argv[])
{
    scanf("%s", a);
    scanf("%s", b);
    int lenb = strlen(b);
    int lena = strlen(a);
    for (int i = 0; i < lenb; i++)
    {
        if (b[i] == '0')
        {
            s[0][i + 1] = s[0][i] + 1;
            s[1][i + 1] = s[1][i];
        }
        else
        {
            s[1][i + 1] = s[1][i] + 1;
            s[0][i + 1] = s[0][i];
        }
    }

    int diff = lenb - lena + 1;
    long long v = 0;
    for (int i = 0; i < lena; i++)
    {
        if (a[i] == '0')
            v += s[1][i + diff] - s[1][i]; 
        else
            v += s[0][i + diff] - s[0][i];
    }
    printf("%I64d\n", v);
    return 0;
}