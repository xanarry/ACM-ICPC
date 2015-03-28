/*A.数字相加
Time Limit: 1000 MS Memory Limit: 65535 K
Description
设有N个正整数，将他们连接成一排，组成一个最大的多位整数。例如:N=3时，
3个整数13,312,343,连成的最大整数为:34331213  
又如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。N个正整数中最大的数不能超过10^10。
Input
多组数据输入，对于每组数据，输入仅一行  N  N个数

Output
输出最大整数
Sample Input
3 13 312 343
4 7 13 4 246
Sample Output
34331213
7424613
Hint
 1<=N<=100;
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string a[1000];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string t1 = a[i] + a[j];
                string t2 = a[j] + a[i];
                if (t1 < t2)
                {
                    string temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            
        }
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
    }
    return 0;
}