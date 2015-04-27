/*
Description
Tomorrow Peter has a Biology exam. He does not like this subject much, but d days 
ago he learnt that he would have to take this exam. Peter's strict parents made 
him prepare for the exam immediately, for this purpose he has to study not less 
han minTimei and not more than maxTimei hours per each i-th day. Moreover, they 
warned Peter that a day before the exam they would check how he has followed their instructions.

So, today is the day when Peter's parents ask him to show the timetable of his 
preparatory studies. But the boy has counted only the sum of hours sumTime spent 
him on preparation, and now he wants to know if he can show his parents a timetable 
schedule with d numbers, where each number schedulei stands for the time in hours 
spent by Peter each i-th day on biology studies, and satisfying the limitations 
imposed by his parents, and at the same time the sum total of all schedulei should equal to sumTime.
Input
Input will consist of multiple test cases.
For each test case. The first input line contains two integer numbers d, 
sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which
Peter studied, and the total amount of hours, spent on preparation. Each of the 
following d lines contains two integer numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), 
separated by a space — minimum and maximum amount of hours that Peter could spent in the i-th day.
Output
In the first line print YES, and in the second line print d numbers (separated by a space), each 
of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he 
followed his parents' instructions; or print NO in the unique line. If there are many solutions, 
please make the large number of possible at the begin.
Sample Input
1 48
5 7
2 5
0 1
3 5
Sample Output
NO
YES
1 4
*/
#include <iostream>
using namespace std;

struct Time_range
{
    int mint, maxt;
};

Time_range time_range[500];

int main(int argc, char const *argv[])
{
    int day, hours;
    while (cin >> day >> hours)
    {
        int minh = 0, maxh = 0;
        for (int i = 0; i < day; i++)
        {
            cin >> time_range[i].mint >> time_range[i].maxt;
            minh += time_range[i].mint;
            maxh += time_range[i].maxt;
        }
        if (minh > hours || maxh < hours)
            cout << "NO" << endl;
        else
        {
            for (int i = 0; i < day; i++)
            {
                while (time_range[i].mint < time_range[i].maxt)
                {
                    if (minh < hours)
                    {
                        minh++;
                        time_range[i].mint++;
                    }
                    else
                        break;
                }
            }
            cout << "YES" << endl;
            for (int i = 0; i < day; ++i)
                cout << time_range[i].mint << " ";
            cout << endl;
        }
    }
    return 0;
}

/*
3 7
2 3
1 4
4 8

3 10
2 3
1 4
4 8

3 13
2 3
1 4
4 8

3 15
2 3
1 4
4 8

3 6
2 3
1 4
4 8

3 29
2 3
1 4
4 8
*/
