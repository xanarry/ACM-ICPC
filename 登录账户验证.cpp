/*一个账户可以使用多种方式登录, 比如说可以使用用户名, 邮箱, 手机号码等等, 但是最终都指向同一个账户, 现在给你一系列用户及其登录方式, 保证不同用户的登录方式没有交集, 现在输入任何一个可以用来登录的账户, 请指出这个账户的所属人
输入人数n
后面n行分别输入用户的唯一ID和一系列该用户的登录方式(每个用户数量不固定)
输入任何一个账户的任何一种登录方式, 请输出这个账户下的唯一ID

输入
5
1 
2 13222222222 2@163.com
3 15333333333 noname
4 name4 name5 444@444.com name444
5 5@555.com
noname
输出
3
*/

#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    map<string, string> m;
    string id;
    string line;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, line);
        int pos = 0, pre = 0;
        while ((pos = line.find_first_of(" ", pos)) != string::npos)
        {

            if (pre == 0)
                id = line.substr(pre, pos - pre);
            else
                m[line.substr(pre, pos - pre)] = id;
            pos++;
            pre = pos;
        }
        m[line.substr(pre, line.length() - pre)] = id;
    }
    cin >> line;
    cout << m[line] << endl;
    return 0;
}