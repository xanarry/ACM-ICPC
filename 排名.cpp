/*小2得到了一份没有排名的成绩单, 上面有数学语文和英语的成绩, 小2很想知道任何一个人的排名, 你是他学计算机的好基友, 请你帮他写个程序解决这个问题
第一行n(1<=n<=10000), 表示学生数量
接下来n行, 每行包含4项, 姓名, 数学成绩, 语文成绩, 英语成绩
最后输入一个学生的姓名, 输入其总分和排名

输入
5
james 7 4 6
bob 3 4 7
cindy 7 3 7
mess 6 4 9
abort 8 6 7
cindy
输出
cindy 17 3
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Stu
{
    string name;
    int a, b, c, s, r;
    bool operator< (const Stu stu) const
    {
        return s > stu.s;
    }
};

int main(int argc, char const *argv[])
{
    int n, i = 0, t = 0;
    string name;
    cin >> n;
    vector<Stu> stulist;
    while (n--)
    {
        Stu stu;
        cin >> stu.name >> stu.a >> stu.b >> stu.c;
        stu.s = stu.a + stu.b + stu.c;
        stulist.push_back(stu);
    }
    sort(stulist.begin(), stulist.end());

    cin >> name;
    for ( ; i < stulist.size(); i++)
    {
        if (i == 0)
            stulist[i].r = 1;
        else
        {
            if (stulist[i].s < stulist[i - 1].s)
            {
                stulist[i].r = stulist[i - 1].r + 1 + t;
                t = 0;
            }
            else
                stulist[i].r = stulist[i - 1].r, t++;
        }
        if (stulist[i].name == name)
        {
            cout << stulist[i].name << " " << stulist[i].s << " " << stulist[i].r << endl;
            return 0; 
        }
    }
    cout << "NONE" << endl;
    return 0;
}