/*输入
acm.hust.edu.cn
输出
cn.edu.hust.acm
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string domain;
    vector<string> v;
    int pos = 0, pre = 0;
    cin >> domain;
    while ((pos = domain.find_first_of(".", pos)) != string::npos)
    {
        v.push_back(domain.substr(pre, pos - pre));
        pre = ++pos;
    }

    v.push_back(domain.substr(pre, domain.length() - pre));
    for (int i = v.size() - 1; i > 0; i--)
        cout << v[i] << ".";
    cout << v[0] << endl;
    return 0;
}