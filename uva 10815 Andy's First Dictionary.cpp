/*
Andy, 8, has a dream - he wants to produce his very own dictionary. This is not an easy task for him, as the number of words that he knows is, well, not quite enough. Instead of thinking up all the words himself, he has a briliant idea. From his bookshelf he would pick one of his favourite story books, from which he would copy out all the distinct words. By arranging the words in alphabetical order, he is done! Of course, it is a really time-consuming job, and this is where a computer program is helpful.
You are asked to write a program that lists all the different words in the input text. In this problem, a word is defined as a consecutive sequence of alphabets, in upper and/or lower case. Words with only one letter are also to be considered. Furthermore, your program must be CaSe InSeNsItIvE. For example, words like "Apple", "apple" or "APPLE" must be considered the same.
Input
The input file is a text with no more than 5000 lines. An input line has at most 200 characters. Input is terminated by EOF.
Output
Your output should give a list of different words that appears in the input text, one in a line. The words should all be in lower case, sorted in alphabetical order. You can be sure that he number of distinct words in the text does not exceed 5000.
Sample Input
Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."

So they went home.
Sample Output
a
adventures
blondes
came
disneyland
fork
going
home
in
left
read
road
sign
so
the
they
to
two
went
were
when
*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	stringstream temp;
	string input = "";
	string t;
	while (getline(cin, t)) 
	{
		input += " " + t;
	}//接收文本

	for (int i = 0; i < input.length(); i++)//将输入的文本转为为只有小写字母和空格的字符串
	{
		if (isalpha(input[i]))
			input[i] = tolower(input[i]);
		else
			input[i] = ' ';
	}

	stringstream ss(input);//将字符串构造层字符串流
	set<string> dict;//单词集合，set是有序的
	string buf;
	while (ss >> buf)//从构造的流中获取输入的单词
		dict.insert(buf);

	for (set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)//迭代输出set中的单词
		cout << *iter << endl;
	return 0;
}

/*
a
adventures
blondes
came
disneyland
disneylandtwo
fork
going
home
in
left
read
sign
so
the
theroad
they
to
went
were
when
请按任意键继续. . .

*/