#include <iostream>
using namespace std;

//asdfasdfasdf
int a[105][105];
int a90[105][105];
int a18[105][105];
int a27[105][105];
int t[105][105];
int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a90[i][j] = a[m - j - 1][i];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a18[i][j] = a[m - i - 1][m - j - 1];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			a27[i][j] = a[j][m - i - 1];


	cout << "90-----------" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a90[i][j] << " ";
		cout << endl;
	}

	cout << "18-----------" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a18[i][j] << " ";
		cout << endl;
	}

	cout << "27-----------" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a27[i][j] << " ";
		cout << endl;
	}
	return 0;

}
