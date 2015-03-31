/*
HDU - 1372
Knight Moves

Description
A friend of you is doing research on the Traveling Knight Problem (TKP) where you are to 
find the shortest closed tour of knight moves that visits each square of a given set of n 
squares on a chessboard exactly once. He thinks that the most difficult part of the problem 
is determining the smallest number of knight moves between two given squares and that, once 
you have accomplished this, finding the tour would be easy. 
Of course you know that it is vice versa. So you offer him to write a program that solves 
the "difficult" part. 

Your job is to write a program that takes two squares a and b as input and then determines 
the number of knight moves on a shortest route from a to b. 
 
Input
The input file will contain one or more test cases. Each test case consists of one line 
containing two squares separated by one space. A square is a string consisting of a letter (a-h) 
representing the column and a digit (1-8) representing the row on the chessboard. 
 
Output
For each test case, print one line saying "To get from xx to yy takes n knight moves.". 
 
Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6 
 
Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/
#include <queue>
#include <iostream>
#include <cstring>
#define MAXSIZE 8
using namespace std;

int x[] = {-2, 2, -2, 2, -1, 1, -1, 1};
int y[] = {-1, -1, 1, 1, 2, 2, -2, -2};
int qp[MAXSIZE + 5][MAXSIZE + 5];

struct P
{
    int x, y, depth;
};

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        memset(qp, 0, sizeof(qp));
        queue<P> que;
        P s, e;
        s.x = a[0] - 'a' + 1; s.y = a[1] - '0'; s.depth = 0;
        e.x = b[0] - 'a' + 1; e.y = b[1] - '0';
        qp[s.x][s.y] = 1;
        que.push(s);
        while (!que.empty())
        {
            P ts = que.front();
            que.pop();
            bool end = false;
            for (int i = 0; i < 8; i++)
            {
                P t;
                t.x = ts.x; t.y = ts.y; t.depth = ts.depth;
                if (t.x == e.x && t.y == e.y)
                {
                    end = true; 
                    cout << "To get from " << a << " to " << b << " takes " << t.depth << " knight moves." << endl; 
                    break;
                }
                t.x += x[i]; t.y += y[i]; t.depth = ts.depth + 1;
                if (t.x >= 1 && t.x <= MAXSIZE && t.y >=1 && t.y <= MAXSIZE && qp[t.x][t.y] == 0 ) 
                {
                        qp[t.x][t.y] = 1;
                        que.push(t);
                }
            }
            if (end)
                break;
        }
    }
    return 0;
}
