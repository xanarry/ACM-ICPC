/*
Description
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 1500'th ugly number.

Input and Output
There is no input to this program. Output should consist of a single line as shown below, with <number> replaced by the number computed.

Sample output
The 1500'th ugly number is <number>.
*/
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	const int n = 1500;
	int a[] = {2, 3, 5};
	set<long long> nums;
	priority_queue<long long, vector<long long>, greater<long long> > num_q;
	nums.insert(1);
	num_q.push(1);
	for (int i = 1; ; i++)
	{
		long long basic = num_q.top();
		num_q.pop();
		if (i == n)
		{
			cout << "The " << n << "'th ugly number is " << basic << "." << endl;
			break;
		}

		for (int j = 0; j < 3; j++)
		{
			long long temp = basic * a[j];
			if (!nums.count(temp))
			{
				nums.insert(temp);
				num_q.push(temp);
			}
		}
	}
	return 0;
}