/*
Description
Download as PDF
You are given a string consisting of parentheses () and []. A string of this type is said to be correct:
(a)
if it is the empty string
(b)
if A and B are correct, AB is correct,
(c)
if A is correct, (A ) and [A ] is correct.
Write a program that takes a sequence of strings of this type and check their correctness. 
Your program can assume that the maximum string length is 128.

Input 
The file contains a positive integer n and a sequence of n strings of parentheses () and [], one string a line.

Output 
A sequence of Yes or No on the output file.

Sample Input 
3
([])
(([()])))
([()[]()])()

Sample Output 
Yes
No
Yes
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>

using namespace std;
const int maxn = 300;
char str[maxn];

int main() 
{
    int n = 0;
    cin >> n;
    getchar();
    while(n--) 
    {
        stack<char> parens;
        gets(str);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '[' || str[i] == '(')
                parens.push(str[i]);
            else if (str[i] == ']' || str[i] == ')')
            {
                if (parens.empty())
                {
                    parens.push(str[i]);
                    break;
                }
                else if ((parens.top() == '(' && str[i] == ')') || (parens.top() == '[' && str[i] == ']'))
                    parens.pop();
            }
        }
        if (parens.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}