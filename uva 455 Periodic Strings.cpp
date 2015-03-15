/*
 Periodic Strings
A character string is said to have period k if it can be formed by concatenating one or more repetitions of another string of length k. For example, the string "abcabcabcabc" has period 3, since it is formed by 4 repetitions of the string "abc". It also has periods 6 (two repetitions of "abcabc") and 12 (one repetition of "abcabcabcabc").

Write a program to read a character string and determine its smallest period.

Input

The first line oif the input file will contain a single integer N indicating how many test case that your program will test followed by a blank line. Each test case will contain a single character string of up to 80 non-blank characters. Two consecutive input will separated by a blank line.

Output

An integer denoting the smallest period of the input string for each input. Two consecutive output are separated by a blank line.

Sample Input

1

HoHoHo
Sample Output

2
*/

#include <iostream>
#include <set>
using namespace std;
bool compares(string a, int start);
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
        string no;
        getline(cin, no);
		string a;
		cin >> a;
       
		for (int i = 1; i <= a.length(); i++)//方法是依次截取1-a.length()长度的字串
		{
            unsigned int start = 0;
            if (a.length() % i == 0)
            {
                set<string> subs;
                while (start < a.length())
                {
                    string sub = a.substr(start, i);
                    subs.insert(sub);
                    start += i;
                }
                if (subs.size() == 1)
                {
                    cout << i << endl;
                    if (n)
                        cout << endl;
                    break;
                } 
            }
		}
	}
	return 0;
}