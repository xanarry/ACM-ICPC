#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    int score;
    int rank;
    bool operator< (Student a) const
    {
        return score > a.score;
    }
};

Student students[100];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> students[i].name >> students[i].score;
    sort(students, students + n);
    students[0].rank = 1;
    int pre = 1;
    int scount = 1;
    for (int i = 1; i < n; i++)
    {
        if (students[i].score < students[i - 1].score)
        {
            students[i].rank = pre + scount;
            pre = students[i].rank;
            scount = 1;
        }
        else
        {
            students[i].rank = pre;
            scount++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << students[i].name << " " << students[i].score << " " << students[i].rank << endl;
    return 0;
}
