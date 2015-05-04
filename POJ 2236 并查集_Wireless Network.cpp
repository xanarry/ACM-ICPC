#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
    int p;
    bool state;
};

Point points[1010];

int find_set(int x)
{
    if (points[x].p == x)
        return x;
    else
        return points[x].p = find_set(points[x].p);
}

double dist(Point a, Point b)
{
    return sqrt((double(a.x- b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int main(int argc, char const *argv[])
{
    char opt;
    int n, maxlen, a, b;
    cin >> n >> maxlen;
    for (int i = 1; i <= n; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].p = i;
        points[i].state = false;
    }

    while (cin >> opt)
    {
        if (opt == 'O')
        {
            cin >> a;
            points[a].state = true;
            for (int i = 1; i <= n; i++)
                if (dist(points[a], points[i]) <= maxlen)
                {
                    if (find_set(a) != find_set(i) && points[i].state == true)
                        points[find_set(i)].p = find_set(a);
                }
        }
        
        if (opt == 'S')
        {
            cin >> a >> b;
            if (find_set(a) == find_set(b))
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
    return 0;
}
