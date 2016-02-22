#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int kase, n, t, lens[55], d[11000], f[11000]; 
int main(int argc, char const *argv[])
{
    cin >> kase;
    for (int k = 1; k <= kase; k++)
    {
        cin >> n >> t;
        for (int i = 1; i <= n; i++)
            cin >> lens[i];//each lens[i] less than 180

        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            for (int j = t - 1; j >= lens[i]; j--)
            {
                //需要优先让歌曲数目最大的情况下,再去选择总时长最长的.
                if (d[j - lens[i]] + 1 == d[j])//此时有两种状态都能得到歌曲数最大,那么应该选择时间最长的状态
                    f[j] = max(f[j], f[j - lens[i]] + lens[i]);//取时间最长
                else if (d[j - lens[i]] + 1 > d[j])
                    f[j] = f[j - lens[i]] + lens[i];
                d[j] = max(d[j], d[j - lens[i]] + 1);
            }
        }
        cout << "Case " << k << ": " << d[t - 1] + 1 << " " << 678 + f[t - 1] << endl;
    }
    return 0;
}