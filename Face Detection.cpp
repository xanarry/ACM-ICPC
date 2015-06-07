/*
http://codeforces.com/contest/549/problem/A
给定一个矩阵, 判断里面包含几个完整face字母
*/
#include <iostream>
#include <set>
#include <string>
using namespace std;

char a[55][55];
int main(int argc, char const *argv[])
{
    int m, n;
    string line;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
            a[i][j] = line[j];
    }

    int sum = 0;
    set<char> face;
    face.insert('f');
    face.insert('a');
    face.insert('c');
    face.insert('e');
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            set<char> fs;
            if (i + 1 < m && j + 1 < n)
            {
                fs.insert(a[i][j]);
                fs.insert(a[i][j + 1]);
                fs.insert(a[i + 1][j]);
                fs.insert(a[i + 1][j + 1]);
            }
            if (fs == face)
                sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
