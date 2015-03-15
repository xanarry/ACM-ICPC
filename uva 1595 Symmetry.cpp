/*
Description
The figure shown on the left is left-right symmetric as it is possible to fold the sheet of paper along a vertical line,
drawn as a dashed line, and to cut the figure into two identical halves. The figure on the right is not left-right symmetric
as it is impossible to find such a vertical line.

Write a program that determines whether a figure, drawn with dots, is left-right symmetric or not. The dots are all distinct.
Input
The input consists of T test cases. The number of test cases T is given in the first line of the input file. The first line
of each test case contains an integer N , where N ( 1 < N < 1, 000) is the number of dots in a figure. Each of the
following N lines contains the x-coordinate and y-coordinate of a dot. Both x-coordinates and y-coordinates are integers
between -10,000 and 10,000, both inclusive.
Output
Print exactly one line for each test case. The line should contain `YES' if the figure is left-right symmetric. and `NO', otherwise.
The following shows sample input and output for three test cases.
Sample Input
3
5
-2 5
0 0
6 5
4 0
2 3
4
2 3
0 4
4 0
0 0
4
5 14
6 10
5 10
6 14
Sample Output
YES
NO
YES
*/
#include <iostream>
#include <set>

using namespace std;

struct POINT
{
	double x, y;
	bool operator< (const POINT &b) const
	{
		if (x < b.x)
			return true;
		else if (x == b.x)
		{
			return y < b.y;
		}
		else
			return false;
	}
	POINT(double a, double b){x = a; y = b;}
	POINT(){}
};

int main(int argc, char const *argv[])
{
	int n, m;
	double x, y;
	cin >> m;
	while (m--)
	{
		cin >> n;
		set<POINT> ps;
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			ps.insert(POINT(x, y));
			sum += (double)x;
		}
		double mid = sum / n;
		bool ifno = false;
		for (set<POINT>::iterator iter = ps.begin(); iter != ps.end(); ++iter)
		{
			if (iter->x <= mid)
			{
				if (ps.find( POINT(iter->x + (mid - iter->x) * 2, iter->y)) == ps.end())
				{
					ifno = true;
					break;
				}
			}
		}
		if (ifno)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
/*
10
5
-2 5
0 0
2 3
6 5
4 0
5
0 4
0 0
4 0
2 3
4 4
4
0 0
2 3
0 4
4 0
5
-2 0
-1 0
0 0
1 0
2 0
3
0 0
0 1
0 -1
3
1 0
-1 0
0 0
10
-2 5
0 0
2 3
6 5
4 0
0 4
0 0
4 0
2 3
4 4
5
-2 5
0 0
6 5
4 0
2 3
4
2 3
0 4
4 0
0 0
4
5 14
6 10
5 10
6 14
yes
yes
no
yes
no
yes
yes
yes
no
yes

*/
