/*
Description
由于硕硕的疏忽，硕硕的电脑被你们提交的程序搞坏了。
这个程序是这样的，他会从1开始到无穷大，一直往电脑里面输入十进制的数字。
1,2,3,……
还好硕硕的电脑是五星级神机，有保护。只能输入二进制数。比如你输入了15，
因为15不是二进制数，所以系统会提示：我是拒绝的~那么这个数就输入失败了。
当硕硕发现自己的电脑中招了之后，病毒已经从1开始输入到n了。
硕硕想知道，此时有多少个数据被成功输入到电脑中了。。。。。。
Input
多组数据输入，每行一个正整数 n (1 ≤ n ≤ 109).
Output
每组数据输出一行，每行一个正整数.
Sample Input
10
Sample Output
2
HINT
当n=10的时候，只有两个数字被成功读取了。即： 1 和 10.
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string n;
    int m;
    while (cin >> n)
    {
        for (m = 1; m < n.length(); m++)
            if (n[m] > '1')
                break;
        int sum = 0;
        int t = 1;
        for (int i = n.length() - 1; i >= 0; i--)
        {
            if (i >= m)
                sum += t;
            else
                if (n[i] != '0')
                    sum += t;
            t *= 2;
        }
        cout << sum << endl;
    }  
    return 0;
}

/*
1
10 11 openSUSE-13.2-DVD-x86_64
100 101 111
1000 1001 1011 1111
10000 10001 1011 10011 10111 11111
56789
101111
110
234
*/