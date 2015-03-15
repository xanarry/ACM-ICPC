/*
You are working in a team that writes Incredibly Customizable Programming Codewriter (ICPC) which is basically a text editor with bells and whistles. You are working on a module that takes a piece of code containing some definitions or other tabular information and aligns each column on a fixed vertical position, while keeping the resulting code as short as possible, making sure that only whitespaces that are absolutely required stay in the code. So, that the first words on each line are printed at position p1 = 1; the second words on each line are printed at the minimal possible position p2, such that all first words end at or before position p2 - 2; the third words on each line are printed at the minimal possible position p3, such that all second words end at or before position p3 - 2, etc.
For the purpose of this problem, the code consists of multiple lines. Each line consists of one or more words separated by spaces. Each word can contain uppercase and lowercase Latin letters, all ASCII punctuation marks, separators, and other non-whitespace ASCII characters (ASCII codes 33 to 126 inclusive). Whitespace consists of space characters (ASCII code 32).
Input 
The input file contains one or more lines of the code up to the end of file. All lines (including the last one) are terminated by a standard end-of-line sequence in the file. Each line contains at least one word, each word is 1 to 80 characters long (inclusive). Words are separated by one or more spaces. Lines of the code can have both leading and trailing spaces. Each line in the input file is at most 180 characters long. There are at most 1000 lines in the input file.
Output 
Write to the output file the reformatted, aligned code that consists of the same number of lines, with the same words in the same order, without trailing and leading spaces, separated by one or more spaces such that i-th word on each line starts at the same position pi.

Note for the Sample:
The `$ \sqcup$' character in the example below denotes a space character in the actual files (ASCII code 32).

Sample Input 
  start:  integer;    // begins here
stop: integer; //  ends here  
 s:  string;   
c:   char; // temp

Sample Output 
start: integer; // begins here 
stop:  integer; // ends   here 
s:     string;
c:     char;    // temp
*/
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

string words[1005][100];//将单词保存到二维数组
int maxlen[100];//用此数组保存每一列单词中单词的最大长度
const string END = "_*_";//标记行末

int main(int argc, char const *argv[])
{
	memset(maxlen, 0, sizeof(maxlen));//初始化最大长度为0
	string sline;
	int rows = 0, cols;
	while (getline(cin, sline))//获取每行
	{
		cols = 0;
		stringstream ss(sline);
		while (ss >> words[rows][cols])//输入每行中的单词
		{
			maxlen[cols] = max(maxlen[cols], (int)words[rows][cols].length());//更新该列单词的最大长度
			cols++;
		}
		words[rows][cols++] = END;//标记结尾
		rows++;
	}

	for (int i = 0; i < rows; i++)
	{
		int j = 0;
		while (words[i][j] != END)
		{
			cout << words[i][j];//输出单词
			if (words[i][j + 1] != END)
				for (int s = 0; s <= maxlen[j] - (int)words[i][j].length(); s++)//补全空格
					cout << " ";
			j++;
		}
		cout << endl;
	}
	return 0;
}

/*
  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp

start: integer; // begins here
stop:  integer; // ends   here 
s:     string;
c:     char;    // temp
*/

