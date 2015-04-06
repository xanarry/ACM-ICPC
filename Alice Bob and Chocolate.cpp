/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=20953
Description
Alice and Bob like games. And now they are ready to start a new game. 
They have placed n chocolate bars in a line. Alice starts to eat chocolate
 bars one by one from left to right, and Bob — from right to left. For 
 each chocololate bar the time, needed for the player to consume it, is 
 known (Alice and Bob eat them with equal speed). When the player consumes
  a chocolate bar, he immediately starts with another. It is not allowed to 
  eat two chocolate bars at the same time, to leave the bar unfinished and 
to make pauses. If both players start to eat the same bar simultaneously,
Bob leaves it to Alice as a true gentleman.

How many bars each of the players will consume?

Input
The first line contains one integer n (1 ≤ n ≤ 105) — the amount of bars on 
the table. The second line contains a sequence t1, t2, ..., tn (1 ≤ ti ≤ 1000), 
where ti is the time (in seconds) needed to consume the i-th bar (in the order from left to right).

Output
Print two numbers a and b, where a is the amount of bars consumed by Alice, and b 
is the amount of bars consumed by Bob.

Sample Input
Input
5
2 9 8 2 7
Output
2 3
*/
#include <iostream>
using namespace std;

int a[100000];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l, r;
    r = a[n - 1];
    l = a[0];
    int i = 1, j = n - 2;
    while (i <= j)
    {
        if (l < r)
            l += a[i++];
        else if (l > r)
            r += a[j--];
        else
            l += a[i++];
    }
    cout << i << " " << n - i << endl;
    return 0;
}