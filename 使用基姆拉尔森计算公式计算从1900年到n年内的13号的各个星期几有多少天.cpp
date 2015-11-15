#include <iostream>
#include <map>
using namespace std;

int getWeekDay(int y, int m, int d)
{
    if(m == 1 || m == 2)
    {
        m += 12;
        y--;
    }
    int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return week + 1; //返回星期1到星期7
}

int main()
{
    map<int, int> wmap;
    int n;
    cin >> n;
    for (int i = 1900; i < 1900 + n; i++)
        for (int j = 1; j <= 12; j++)
            wmap[getWeekDay(i, j, 13)]++;
    cout << wmap[6] << " " << wmap[7] << " " << wmap[1] << " " << wmap[2] << " " << wmap[3] << " " << wmap[4] << " " << wmap[5] << endl;
    return 0;
}