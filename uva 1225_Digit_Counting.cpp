/*
Trung is bored with his mathematics homeworks. He takes a piece of chalk and starts writing a sequence of consecutive integers starting with 1 to N (1 < N < 10000) . After that, he counts the number of times each digit (0 to 9) appears in the sequence. For example, with N = 13 , the sequence is:

12345678910111213

In this sequence, 0 appears once, 1 appears 6 times, 2 appears 2 times, 3 appears 3 times, and each digit from 4 to 9 appears once. After playing for a while, Trung gets bored again. He now wants to write a program to do this for him. Your task is to help him with writing this program.

Input

The input file consists of several data sets. The first line of the input file contains the number of data sets which is a positive integer and is not bigger than 20. The following lines describe the data sets.

For each test case, there is one single line containing the number N .

Output

For each test case, write sequentially in one line the number of digit 0, 1,...9 separated by a space.

Sample Input

2
3
13
Sample Output

0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 1
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
    cin >> n;
    while (n--)
    {
        int a[10];//保存每个数字出现的次数
        memset(a, 0, sizeof(a));
        int num;
        stringstream ss;
        cin >> num;
        for (int i = 1; i <= num; i++)
            ss << i;
        string snum = ss.str();
        for (int i = 0; i < snum.length(); i++)
            a[snum[i] - '0']++;//出现一次，对应下标数组元素的值自增一个值

        for (int i = 0; i < 9; i++)//输出0-9每个数出现的次数
            cout << a[i] << ' ';
        cout << a[9] << endl;
    }
	return 0;
}

