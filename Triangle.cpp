/*
Description
Johnny has a younger sister Anne, who is very clever and smart. As she came home from the 
kindergarten, she told his brother about the task that her kindergartener asked her to solve. 
The task was just to construct a triangle out of four sticks of different colours. Naturally, 
one of the sticks is extra. It is not allowed to break the sticks or use their partial length. 
Anne has perfectly solved this task, now she is asking Johnny to do the same.

The boy answered that he would cope with it without any difficulty. However, after a while he 
found out that different tricky things can occur. It can happen that it is impossible to 
construct a triangle of a positive area, but it is possible to construct a degenerate 
triangle. It can be so, that it is impossible to construct a degenerate triangle even. 
As Johnny is very lazy, he does not want to consider such a big amount of cases, he asks you to help him.
Input
Input will consist of multiple test cases.
For each test case.The first line of the input contains four space-separated positive 
integer numbers not exceeding 100 — lengthes of the sticks.
Output
Output TRIANGLE if it is possible to construct a non-degenerate triangle. Output 
SEGMENT if the first case cannot take place and it is possible to construct a degenerate 
triangle. Output IMPOSSIBLE if it is impossible to construct any triangle. Remember that 
you are to use three sticks. It is not allowed to break the sticks or use their partial length.
Sample Input
4 2 1 3
7 2 2 4
3 5 9 1
Sample Output
TRIANGLE
SEGMENT
IMPOSSIBLE
HINT
Degenerate triangle is not a triangle. It’s 3 sticks end to end. And 3 ponits in one line.
*/
#include <iostream>
using namespace std;

bool checkT(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
        return true;
    else
        return false;
}

bool checkS(int a, int b, int c)
{
    if (a + b == c || a + c == b || b + c == a)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        int t = 0;
        int m[4] = {0};
        if (checkT(a, b, c)) {t++; m[0] = 1;};
        if (checkT(a, b, d)) {t++; m[1] = 1;};
        if (checkT(a, c, d)) {t++; m[2] = 1;};
        if (checkT(b, c, d)) {t++; m[3] = 1;};
        if (t != 0)
            cout << "TRIANGLE" << endl;
        else
        {
            if (m[0] != 1 && checkS(a, b, c))
                cout << "SEGMENT" << endl; 
            else if (m[1] != 1 &&  checkS(a, b, d))
                cout << "SEGMENT" << endl; 
            else if (m[2] != 1 && checkS(a, c, d))
                cout << "SEGMENT" << endl; 
            else if (m[3] != 1 &&  checkS(b, c, d))
                cout << "SEGMENT" << endl; 
            else
                cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}