/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19085
给定一系列矩阵，然后输入矩阵的乘法，如果能够相乘，则输出乘法执行次数，
能相乘则输出error
Sample Input
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))
Sample Output
0
0
0
error
10000
error
3500
15000
40500
47500
15125
*/
#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n;
    char mn;
    map<char, pair<int ,int> > mps;
    for (int i = 0; i < n; i++)
    {
        cin >> mn >> a >> b;
        mps[mn] = {a, b};
    }
    string str;
    while (cin >> str)
    {
        stack<pair<int, int> > matrixs;
        stack<char> parenthesis;
        int total = 0; 
        if (str.length() == 1 && isupper(str[0]))
            cout << 0 << endl;
        else
        {
            bool mark = false;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '(')
                    parenthesis.push(str[i]);
                else if (isupper(str[i]))
                    matrixs.push(mps[str[i]]);
                else
                {
                    pair<int, int> r, a, b;
                    a = matrixs.top(); matrixs.pop();
                    b = matrixs.top(); matrixs.pop();
                    if (b.second == a.first)
                    {
                        r = make_pair(b.first, a.second);
                        total += b.first * b.second * a.second;
                        matrixs.push(r);
                        parenthesis.pop();
                    }
                    else
                    {
                        cout << "error" << endl;
                        mark = true;
                        break;
                    }
                }
            }
            if (!mark)
                cout << total << endl;
        } 
    }
    return 0;
}