#include <iostream>
using namespace std;

int main()
{
	cout << "input a limitation:";
	int limit;
	cin >> limit;
	int sum = 0;
	for (int i = 0; i <= limit; i++)
		sum += i;
	cout << sum << endl;
	return 0;
}
