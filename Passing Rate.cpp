/*
Passing Rate
Desciption
    The result of final exam have been released already. however, the result of exam is very poor generally
,which makeks the teacher some headaches, Accordance with school policy. the pass rates of this course can't
be less P%. so to set the pass line has become a seriouss problem, as the number of students, can you write a 
program to quickly calculate how much should be set up to pass line for it?

Input        
    the first line contain one interger T(T<= 100), it means the number of test cases, for each test case.
the first line will contain N and P separated by a space, Giving the number of students and the passing rate 
respectively, Agter that will be ont line containing N intergers score i(0<= i <= 100) separated by space.
Represents all student achivevment

Output
    For each test case, print one integer means the max of passing rate.

Sample Input
2
4 50
40 50 60 70
4 60
40 50 60 70

Sample Output
60
50
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a, b;
    int scr[110];
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < a; j++)
            cin >> scr[j];
        sort(scr, scr + a);

        if (b == 0)
        {
            cout << 100 << endl;
            continue;
        }
        double t = (double)a * (double)b / 100.0;

        if (t > floor(t))
            t++;
        cout << scr[a - (int)t] << endl;
    }
    return 0;
}
