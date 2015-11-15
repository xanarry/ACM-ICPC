#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, i = 31;
    int a[32];
    memset(a, 0, sizeof(a));//初始化数组每个元素为0
    cin >> n;
    if (n < 0)//如果n是负数
    {
        a[0] = 1;//设置最高位1
        n = -n;//取绝对值
    }
    while (n > 0)//计算二进制编码
    {
        a[i--] = n % 2;
        n /= 2;
    }
    //正数的补码等于二进制码, 负数的则对各位取反, 然后在加1
    if (a[0])
    {
        for (int i = 1; i < 32; i++)
            a[i] = 1 - a[i];//各位取反
        a[31]++;//加1
        for (int i = 31; i >= 0; i--)//处理进位
        {
            if (a[i] > 1)
            {
                a[i] = a[i] % 2;
                a[i - 1]++;
            }
        }
    }
    for (int i = 0; i < 32; i++)
        cout << a[i];
    cout << endl;
    return 0;
}
