#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	string str;
    int n;
	cin>>n;
	while (n--)
	{
		getchar();
		getline(cin, str);
		int s = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				for (int j = i - 1; j >= s; j--)
					cout << str[j];
				cout << " ";
				s = i + 1;
			}
		}
		for (int j = str.length() - 1; j >= s; j--)
			cout << str[j];
		cout << endl;
	}
	return 0;
}

