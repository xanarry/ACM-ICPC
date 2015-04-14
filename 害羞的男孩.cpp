/*
Description
某一所古老的学校，有一群害羞的boys。
放学了，大家到食堂打饭。如果一名男生的身后是女生，本着女士优先的原则，那么下一秒，他会和这名女生交换位置。
现在给出你一个队列，求n秒之后的队列。
Input
输入包含多组数据,请处理到末尾
对于每组输入：第一行两个数n和k，（0 < n,k < 100）表示这个队列总共有n名学生。经过了k秒。
第二行为一个字符串，为学生们现在的队列。B代表男孩，G代表女孩。
Output
对于每组输入，输出一行，为k秒之后的队列。
Sample Input
4 1
BGBG
Sample Output
GBGB
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    string que;
    while (cin >> n >> k)
    {
        cin >> que;
        while (k--)
            for (int i = 0; i < n - 1; i++)
                if (que[i] < que[i + 1])
                {
                    swap(que[i], que[i + 1]);
                    i++;
                }
        cout << que << endl;
    }
    return 0;
}
