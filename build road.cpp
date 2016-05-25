#include <iostream>
#include <cstring>
using namespace std;

struct Pt
{
    int x1, y1, x2, y2;
    bool hor;
};

Pt p[1010];
int f[1010];

int findset(int x)
{
    if (f[x] == -1)
        return x;
    else
        return f[x] = findset(f[x]);
}

void unionset(int a, int b)
{
    int x = findset(a);
    int y = findset(b);
    if (x != y)
        f[x] = y;
}

bool cross(int i, int j)
{
    if (p[i].hor == p[j].hor) // 同为true, y不变关于x平行, 同为false, x不变关于y平行
    {
        if (p[i].hor == true) //y不变关于x平行
        {
            if (p[i].y1 == p[j].y1) //不变and相同, 才重合
                return (p[i].x1 >= p[j].x1 && p[i].x1 <= p[j].x2 || p[i].x2 >= p[j].x1 && p[i].x2 <= p[j].x2 || p[i].x1 >= p[j].x1 && p[i].x1 <= p[j].x2 || p[j].x1 >= p[i].x1 && p[j].x1 <= p[i].x2);//相交
        }
        else //关于y平行
        {
            if (p[i].x1 == p[j].x1)
               return (p[i].y1 >= p[j].y1 && p[i].y1 <= p[j].y2 || p[i].y2 >= p[j].y1 && p[i].y2 <= p[j].y2 || p[i].y1 >= p[j].y1 && p[i].y1 <= p[j].y2 || p[j].y1 >= p[i].y1 && p[j].y1 <= p[i].y2);//相交
        }
    }
    else //垂直
    {
        if (p[i].hor == true) // i x平行_____
        {
            int x = p[j].x1; //j |
            int y = p[i].y1;
            return (x >= p[i].x1 && x <= p[i].x2 && y >= p[j].y1 && y <= p[j].y2);
        }
        else //j x平行____
        {
            int x =  p[i].x1;// p x[1 3] y 1
            int y =  p[j].y1;// l y 1 x 2                    1                 1
            return (x >= p[j].x1 && x <= p[j].x2 && y >= p[i].y1 && y <= p[i].y2);
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n; 
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        memset(f, -1, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
            if (p[i].y1 == p[i].y2) //all point regard as hor
                p[i].hor = true;
            else
                p[i].hor = false;

            for (int j = 1; j < i; j++)
                if (cross(i, j) == true)
                    unionset(i, j);
        }

        if (findset(1) == findset(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}


/*
2
2 1 2 1
1 1 3 1

1 2 1 2
1 1 1 3
*/
