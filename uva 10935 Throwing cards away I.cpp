/*
Problem B: Throwing cards away I
Given is an ordered deck of n cards numbered 1 to n with card 1 at the top and card n at the bottom. The following operation is performed as long as there are at least two cards in the deck:
Throw away the top card and move the card that is now on the top of the deck to the bottom of the deck.

Your task is to find the sequence of discarded cards and the last, remaining card.
Each line of input (except the last) contains a number n ¡Ü 50. The last line contains 0 and this line should not be processed. For each number from the input produce two lines of output. The first line presents the sequence of discarded cards, the second line reports the last remaining card. No line will have leading or trailing spaces. See the sample for the expected format.
Sample input
7
19
10
6
0
Output for sample input
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int m, n;
	while (1)
	{
		vector<int> cards;
		cin >> n;
		if (!n)
			break;
		for (int i = 1; i <= n; i++)
			cards.push_back(i);

		cout << "Discarded cards:";
		while (cards.size() >= 2)
		{
			int a = cards.front();
			cards.erase(cards.begin());
			cout << " " << a;
			if (cards.size() != 1)
				cout << ",";
			int b = cards.front();
			cards.push_back(b);
			cards.erase(cards.begin());
		}
		cout << "\nRemaining card: ";
		cout << cards.front() << endl;
	}
	return 0;
}
