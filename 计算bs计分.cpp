/*http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=603&pid=1001*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    double scores[] = {1000, 1500, 2000, 2500};
    for (int j = 1; j <= t; j++)
    {
        double sum = 0;
        double a, b;
        for (int i = 0; i < 4; i++)
        {
            cin >> a >> b;
            double temp = (250 - a) / 250 * scores[i];
            temp -= b * 50;
            if (temp < scores[i] * 0.4)
                temp = scores[i] * 0.4;
            sum += temp;
        }
        cout << "Case #" << j << ": " << (int)sum << endl;
    }
    return 0;
}