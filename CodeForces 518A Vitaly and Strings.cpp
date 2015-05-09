/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=125216
方法即为将字符串看成数字,然后对其加1,然后与另外一个比较,如果还是比另外一个小就是yes否则是no
Description
Vitaly is a diligent student who never missed a lesson in his five years of studying in the 
university. He always does his homework on time and passes his exams in time.

During the last lesson the teacher has provided two strings s and t to Vitaly. The strings 
have the same length, they consist of lowercase English letters, string s is lexicographically 
smaller than string t. Vitaly wondered if there is such string that is lexicographically larger 
than string s and at the same is lexicographically smaller than string t. This string should 
also consist of lowercase English letters and have the length equal to the lengths of strings s and t.

Let's help Vitaly solve this easy problem!

Input
The first line contains string s (1 ≤ |s| ≤ 100), consisting of lowercase English letters. 
Here, |s| denotes the length of the string.

The second line contains string t (|t| = |s|), consisting of lowercase English letters.

It is guaranteed that the lengths of strings s and t are the same and string s is lexicographically 
less than string t.

Output
If the string that meets the given requirements doesn't exist, print a single string "No such string" (without the quotes).

If such string exists, print it. If there are multiple valid strings, you may print any of them.

Sample Input
Input
a
c
Output
b

Input
aaa
zzz
Output
kkk

Input
abcdefg
abcdefh
Output
No such string
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    a[a.length() - 1]++;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] > 'z')
        {
            a[i] = 'a';
            a[i - 1]++;
        }
    }
    if (a < b)
        cout << a << endl;
    else
        cout << "No such string" << endl;
    return 0;
}