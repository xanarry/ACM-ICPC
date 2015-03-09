#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int i, j;
	while (cin >> i >> j)
	{
		long long max_l = 0;
		for (int n = min(i, j); n <= max(i, j); n++)
		{
			long long t = n;
			long long times = 1;
			while (t != 1)
			{
				times++;
				if (t % 2)
					t = 3 * t + 1;
				else
					t = t / 2;
			}
			if (times > max_l)
				max_l = times;
		}
		cout << i << " " << j << " " << max_l << endl;
	}
	return 0;
}
