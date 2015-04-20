/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=11632
These days, I am thinking about a question, how can I get a 
problem as easy as A+B? It is fairly difficulty to do such 
a thing. Of course, I got it after many waking nights. 
Give you some integers, your task is to sort these number ascending (升序). 
You should know how easy the problem is now! 
Good luck! 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int m[1005];
int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n;
    while (n--)
    {
        cin >> t;
        for (int i = 0; i < t; i++)
            cin >> m[i];

        sort(m, m + t);
        for (int i = 0; i < t - 1; i++)
            cout << m[i] << " ";
        cout << m[t - 1] << endl;
    }
    return 0;
}

/*
 1 2 3
1 2 3 4 5 6 7 8 9 
*/