/*
There is an objective test result such as ``OOXXOXXOOO". An `O' means a correct answer of a problem and an `X' means a wrong answer. The score of each problem of this test is calculated by itself and its just previous consecutive `O's only when the answer is correct. For example, the score of the 10th problem is 3 that is obtained by itself and its two previous consecutive `O's.

Therefore, the score of ``OOXXOXXOOO" is 10 which is calculated by ``1+2+0+0+1+0+0+1+2+3".

You are to write a program calculating the scores of test results.

Input 

Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing a string composed by `O' and `X' and the length of the string is more than 0 and less than 80. There is no spaces between `O' and `X'.

Output 

Your program is to write to standard output. Print exactly one line for each test case. The line is to contain the score of the test case.

The following shows sample input and output for five test cases.

Sample Input 

5 
OOXXOXXOOO 
OOXXOOXXOO 
OXOXOXOXOXOXOX 
OOOOOOOOOO 
OOOOXOOOOXOOOOX
Sample Output 

10 
9 
7 
55 
30
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;

		int score = 0;
		int single = 1;
		if (str[0] == 'O')
			score = 1;

		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == 'O')
			{
				if (str[i] == str[i - 1])//if meet a serial O need to increase single score
					single++;
				score += single;//only current charactor is O, should record to total score
			}
			else//meet a x need to reset single score
				single = 1;
		}

		cout << score << endl;
	}
	return 0;
}