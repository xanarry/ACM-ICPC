/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=127109
Description
A word or a sentence in some language is called a pangram if all the characters of 
the alphabet of this language appear in it at least once. Pangrams are often used 
to demonstrate fonts in printing or test the output devices.

You are given a string consisting of lowercase and uppercase Latin letters. Check 
whether this string is a pangram. We say that the string contains a letter of the 
Latin alphabet if this letter occurs in the string in uppercase or lowercase.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of characters in the string.

The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

Output
Output "YES", if the string is a pangram and "NO" otherwise.

Sample Input
Input
12
toosmallword
Output
NO
Input
35
TheQuickBrownFoxJumpsOverTheLazyDog
Output
YES
*/
#include <iostream>
#include <set>
#include <cctype>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string a;
    cin >> n;
    set<char> chs;
    if (n < 26)
        cout << "NO" << endl;
    else
    {
        cin >> a;
        for (int i = 0; i < a.length(); i++)
            chs.insert(tolower(a[i]));
        if (chs.size() == 26)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}