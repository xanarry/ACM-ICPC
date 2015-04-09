/*
Description
One hot summer day Pete and his friend Billy decided to buy a watermelon. They chose the biggest and the ripest one, in their opinion. After that the watermelon was weighed, and the scales showed w kilos. They rushed home, dying of thirst, and decided to divide the berry, however they faced a hard problem.

Pete and Billy are great fans of even numbers, that's why they want to divide the watermelon in such a way that each of the two parts weighs even number of kilos, at the same time it is not obligatory that the parts are equal. The boys are extremely tired and want to start their meal as soon as possible, that's why you should help them and find out, if they can divide the watermelon in the way they want. For sure, each of them should get a part of positive weight.
Input
Input will consist of multiple test cases.
For each test case. The first input line contains integer number w (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.
Output
Print YES, if the boys can divide the watermelon into two parts, each of them weighing even number of kilos; and NO in the opposite case.
Sample Input
4
Sample Output
YES
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int mark = 0;
        for (int i = 2; i <= 98; i += 2)
        {
            int t = n - i;
            if (t > 0 && t % 2 == 0)
            {
                cout << "YES" << endl;
                mark = 1;
                break;
            }
        }
        if (mark == 0)
            cout << "NO" << endl;
    }
    return 0;
}