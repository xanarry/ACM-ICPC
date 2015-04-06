/*
Description
在万圣节这天，每个小孩都回去挨家挨户要糖果，但是邻居们只想给出一定数量的糖果，
如果你去的很晚，那么很有可能要不到糖果。
孩子们决定把所有人要来的糖果放到一起，然后平均分摊。但是，每个住户给出的糖果数量
又是不一定相同的，孩子们更关心所有的糖果是否能平均分摊。因此他们只选择一部分住户
去索要糖果。因为大家都是邻居，住的很近，所以只找某些家要糖果，而不去另外一些家，
总感觉怪怪的，因此，大家决定，选择一个起点和一个终点，向在这之间的所有人家索要糖果。
孩子们会根据以往的经验，推测出，每家会给出多少糖果，那么……
你能否找到这样的起点和终点，使得糖果恰好被均分，而且每个孩子获得的糖果数量最多呢？
Input
多组数据输入。对于每组数据输入两行。
第一行包含两个正整数c和n。分别表示children的数量和住户的数量。
第二行包含n个正整数a[i]。分别为按照顺序，每个住户给出的糖果数。
( 1<= n,c,a[i] <= 100,000 ; n>=c )
Output
对于每组数据，输出一行，为每个孩子获得的最多糖果数。
Sample Input
5 5
1 2 3 4 5
Sample Output
3
*/
#include <iostraem>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100010;
long long a[MAX];
int main()
{
	ios::sync_with_stdio(false);
	int c,n;
	while(cin >> c >> n)
	{
		int temp,mo;
		long long sum = 0;
		long long ans = 0;
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			sum += temp;
			mo = sum % c;
			if(mo == 0)
				ans = sum;
			else
			{
				if(a[mo] == 0)
					a[mo] = sum;
				else
					ans = max(ans, sum - a[mo]);
			}
		}
		cout<<ans / c<<endl;
	}
	return 0;
}

//2 3 5 7 9