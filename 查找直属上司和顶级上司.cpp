/*
Description
威廉伯爵去SHENGDIYAGE视察后,觉得人员管理机制不科学
于是威廉伯爵要重新分配员工的从属关系
当威廉伯爵下令IKU a b
表示把a指派为b的上司,如果b已经有其他的上司或者a,b已经有从属关系,则忽略本条命令
有时威廉伯爵想要查询某人的上司,就会下令Q a
这是你需要输出a的直属上司和a的顶级上司
如果a没有任何上司,那么他的直属上司和顶级上司就都是他自己.

Input
输入包含多组数据,对于每组数据
第一行包含两个整数n和m,表示员工数量和命令条数
下面m行,每行一个命令
1<=n,m<=500000.

Output
对于每个询问,输出直属上司和顶级上司

Sample Input
5 10
Q 1
IKU 1 2
Q 2
IKU 5 1
IKU 3 1
Q 1
Q 2
IKU 3 5
Q 2
Q 5

Sample Output
1 1
1 1
5 5
1 5
1 3
3 3
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int p[500005];
int find(int x)
{
    if (p[x] == 0) 
        return x;
    else 
        return find(p[x]);
}

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    string order;
    while (cin >> n >> m)
    {
        memset(p, 0, sizeof(p));
        for (int i = 0; i < m; i++)
        {
            cin >> order;
            if (order == "IKU")
            {
                cin >> a >> b;
                if (find(b) == b && find(a) != find(b))
                    p[b] = a;
            }
            if (order == "Q")
            {
                cin >> a;
                int direct = p[a] == 0 ? a : p[a];
                int indirect = find(a);
                cout << direct << " " << indirect << endl;
            }

        }
    }
    return 0;
}