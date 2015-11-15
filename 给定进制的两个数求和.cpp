#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string nums = "0123456789ABCDEF";
	int base;
	string a, b;
	vector<int> va;
	vector<int> vb;
	cin >> base >> a >> b;
	for (int i = a.length() - 1; i >= 0; i--)
		va.push_back(nums.find(a[i]));
	for (int i = b.length() - 1; i >= 0; i--)
		vb.push_back(nums.find(b[i]));

	int maxlen = a.length() > b.length() ? a.length() : b.length();
	va.resize(maxlen + 1);
	vb.resize(maxlen + 1);

	for (int i = 0; i < va.size(); i++)
	{
		int temp = va[i] + vb[i];
		va[i] = temp % base;
		va[i + 1] += temp / base;
	}

	bool flag = false;
	for (int i = va.size() - 1; i >= 0; i--)
	{
		if (flag)
			cout << nums[va[i]];
		else if (va[i] != 0)
		{
			flag = true;
			cout << nums[va[i]];
		}
	}
	if (!flag)
		cout << 0 << endl;
	cout << endl;
	return 0;
}
