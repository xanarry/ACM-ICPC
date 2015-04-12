/*
Description
给出三个顶点坐标，求三角形的面积。
Input
多组数据输入，每行6个正整数（x1,y1）,（x2,y2）,（x3,y3）.
0< x,y < 100
Output
每组数据输出一行，为三角形的面积。精确到小数点后两位。
Sample Input
4 2 1 3 6 0
7 2 2 4 2 5
3 5 9 1 3 3
Sample Output
2.00
2.50
6.00
*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int ax, ay, bx, by, cx, cy;
    double ab, bc, ac;
    while (cin >> ax >> ay >> bx >> by >> cx >> cy)
    {
        ab = sqrt((ax - bx)*(ax - bx) + (ay - by)*(ay - by));
        ac = sqrt((ax - cx)*(ax - cx) + (ay - cy)*(ay - cy));
        bc = sqrt((bx - cx)*(bx - cx) + (by - cy)*(by - cy));
        double p = (ab + bc + ac) / 2;
        double s = sqrt(p * (p - ab) * (p - bc) * (p - ac));
        printf("%0.2f\n", s);
    }
    return 0;
}