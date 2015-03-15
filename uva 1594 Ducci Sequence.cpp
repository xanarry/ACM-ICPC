/*
A Ducci sequence is a sequence of n-tuples of integers. Given an n-tuple of integers (a1, a2, ... , an), the next n-tuple in the sequence is formed by taking the absolute differences of neighboring integers:
( a1, a2, ... , an)  --> (| a1 - a2|,| a2 - a3|, ... ,| an - a1|)
Ducci sequences either reach a tuple of zeros or fall into a periodic loop. For example, the 4-tuple sequence starting with 8,11,2,7 takes 5 steps to reach the zeros tuple:
(8, 11, 2, 7)  --> (3, 9, 5, 1)  --> (6, 4, 4, 2)  --> (2, 0, 2, 4)  --> (2, 2, 2, 2)  --> (0, 0, 0, 0).
The 5-tuple sequence starting with 4,2,0,2,0 enters a loop after 2 steps:
(4, 2, 0, 2, 0)  --> (2, 2, 2, 2, 4)  --> ( 0, 0, 0, 2, 2)  --> (0, 0, 2, 0, 2)  --> (0, 2, 2, 2, 2)  --> (2, 0, 0, 0, 2)  -->
(2, 0, 0, 2, 0)  --> (2, 0, 2, 2, 2)  --> (2, 2, 0, 0, 0)  --> (0, 2, 0, 0, 2)  --> (2, 2, 0, 2, 2)  --> (0, 2, 2, 0, 0)  -->
(2, 0, 2, 0, 0)  --> (2, 2, 2, 0, 2)  --> (0, 0, 2, 2, 0)  --> (0, 2, 0, 2, 0)  --> (2, 2, 2, 2, 0)  --> ( 0, 0, 0, 2, 2)  --> ...
Given an n-tuple of integers, write a program to decide if the sequence is reaching to a zeros tuple or a periodic loop.
Input 
Your program is to read the input from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer n(3$ \le$n$ \le$15), which represents the size of a tuple in the Ducci sequences. In the following line, n integers are given which represents the n-tuple of integers. The range of integers are from 0 to 1,000. You may assume that the maximum number of steps of a Ducci sequence reaching zeros tuple or making a loop does not exceed 1,000.
Output 
Your program is to write to standard output. Print exactly one line for each test case. Print `LOOP' if the Ducci sequence falls into a periodic loop, print `ZERO' if the Ducci sequence reaches to a zeros tuple.
The following shows sample input and output for four test cases.
Sample Input 
4 
4 
8 11 2 7 
5 
4 2 0 2 0 
7 
0 0 0 0 0 0 0 
6 
1 2 3 1 2 3
Sample Output 
ZERO 
LOOP 
ZERO 
LOOP
*/
#include <iostream>
#include <cmath>
using namespace std;

bool valid(int *a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

void trans(int *a, int n)
{
	int temp = a[0];
	for (int i = 1; i < n; i++)
		a[i - 1] = abs(a[i] - a[i - 1]);
	a[n - 1] = abs(temp - a[n - 1]);
}

int main(int argc, char const *argv[])
{
	int a[20], n, m;
    cin >> m;
    while (m--)
    {
    	cin >> n;
    	for (int i = 0; i < n; i++)
    		cin >> a[i];

    	int tc = 0;
    	while (++tc <= 1000 && valid(a, n))
    		trans(a, n);

    	if (valid(a, n))
    		cout << "LOOP" << endl;
    	else
    		cout << "ZERO" << endl;
    }
	return 0;
}

/*
5
97 41 17 7 3
loop

4
8 11 2 7
0
*/
