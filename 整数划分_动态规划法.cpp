/*
描述
将整数n分成k份，且每份不能为空，任意两份不能相同(不考虑顺序)。
例如：n=7，k=3，下面三种分法被认为是相同的。
1,1,5; 1,5,1; 5,1,1;
问有多少种不同的分法。

输入格式：
多组数据输入。输入n，k (6<n<=200，2<=k<=6)

输出格式：
一个整数，即不同的分法。

样例1
样例输入
7 3

样例输出
4
*/
#include <iostream>
using namespace std;
int fal[201][7];
int main()
{
	int n, k;
	cin >> n >> k;
	fal[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			if (i >= j)
				fal[i][j] = fal[i - j][j] + fal[i - 1][j - 1];
	cout << fal[n][k] << endl;
	return 0;
}
