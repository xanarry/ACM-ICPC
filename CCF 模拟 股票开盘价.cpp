/*
问题描述
　　某股票交易所请你编写一个程序，根据开盘前客户提交的订单来确定某特定股票的开盘价和开盘成交量。
　　该程序的输入由很多行构成，每一行为一条记录，记录可能有以下几种：
　　1. buy p s 表示一个购买股票的买单，每手出价为p，购买股数为s。
　　2. sell p s 表示一个出售股票的卖单，每手出价为p，出售股数为s。
　　3. cancel i表示撤销第i行的记录。
　　如果开盘价为p0，则系统可以将所有出价至少为p0的买单和所有出价至多为p0的卖单进行匹配。因此，
    此时的开盘成交量为出价至少为p0的买单的总股数和所有出价至多为p0的卖单的总股数之间的较小值。
　　你的程序需要确定一个开盘价，使得开盘成交量尽可能地大。如果有多个符合条件的开盘价，你的程序应
    当输出最高的那一个。

输入格式
　　输入数据有任意多行，每一行是一条记录。保证输入合法。股数为不超过108的正整数，出价为精确到恰好小数点后两位的正实数，
    且不超过10000.00。

输出格式
　　你需要输出一行，包含两个数，以一个空格分隔。第一个数是开盘价，第二个是此开盘价下的成交量。开盘价需要精确到小数点后恰好两位。

样例输入
buy 9.25 100
buy 8.88 175
sell 9.00 1000
buy 9.00 400
sell 8.92 400
cancel 1
buy 100.00 50
样例输出
9.00 450
评测用例规模与约定
对于100%的数据，输入的行数不超过5000。
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    string a;
    int t = 1, count, index;
    double price;
    pair<char, double> dindex[1000];//额外数组保存输入的顺序，用于删除是查找下标
    map<pair<char, double>, int> data;//key为(买卖状态，出价), 股票量,有序的，买票在前，售票在后
    while (cin >> a)
    {
        if (a[0] != 'c')
        {
            cin >> price >> count;
            data[pair<char, double>(a[0], price)] = count;
            dindex[t++] = pair<char, double>(a[0], price);//保存每条数据的下标
        }
        else
        {
            cin >> index;
            map<pair<char, double>, int>::iterator iter = data.find(dindex[index]);//通过保存的下标搜索迭代器然后删除数据
            data.erase(iter);
        }
    }

    //找到在map中买与卖的分离点
    map<pair<char, double>, int>::iterator break_iter = data.begin();
    for (; break_iter != data.end(); ++break_iter)
    {
        cout << break_iter->first.first << " " << break_iter->first.second << " " << break_iter->second << endl;
        if (break_iter->first.first == 's')
            break;
    }

    pair<double, int> buyp[1000]; //构造买股票前缀和数组
    map<pair<char, double>, int>::iterator start = --data.begin();
    cout << (start == data.begin()) << endl;
    int buynum = 0;
//    --break_iter;
    map<pair<char, double>, int>::iterator iter = --break_iter; 
        cout << iter->first.first << " " << iter->first.second << " " << iter->second << endl;
     cout << (iter == start) << endl;
    for (map<pair<char, double>, int>::iterator iter = --break_iter; iter != start; --iter)
    {

        cout << iter->first.first << " " << iter->first.second << " " << iter->second << endl;
    /*    if (buynum == 0)
            buyp[buynum] = pair<double, int>(iter->first.second, iter->second);
        else
            buyp[buynum] = pair<double, int>(iter->first.second, buyp[buynum - 1].second + iter->second);
        buynum++;*/
    }

    pair<double, int> sellp[1000];//后缀买股票的前缀和数组
    int sellnum = 0;
    for (map<pair<char, double>, int>::iterator iter = ++break_iter; iter != data.end(); ++iter)
    {
        cout << iter->first.first << " " << iter->first.second << " " << iter->second << endl;

        if (sellnum == 0)
            sellp[sellnum] = pair<double, int>(iter->first.second, iter->second);
        else
            sellp[sellnum] = pair<double, int>(iter->first.second, sellp[sellnum - 1].second + iter->second);
        sellnum++;
    }

    //以下分别将买与卖的数组信息转换为map形式保存，方便后续查找
    map<double, int> mbuyp, msellp;//用来保存结果
    for (int i = 0; i < buynum; i++)
    {
        cout << buyp[i].first << " " << buyp[i].second << endl;
        mbuyp[buyp[i].first] = buyp[i].second;
    }

    for (int i = 0; i < sellnum; i++)
        msellp[sellp[i].first] = sellp[i].second;

    pair<double, int> result = *mbuyp.begin();//遍历所有买的价格
    for (map<double, int>::iterator iter = mbuyp.begin(); iter != mbuyp.end(); ++iter)
    {
        if (msellp.count(iter->first))
            result = (iter->second < msellp[iter->first] ? *iter : *msellp.find(iter->first));
        else
            result = *iter;
    }
    //遍历所有买的价格
    for (map<double, int>::iterator iter = msellp.begin(); iter != msellp.end(); ++iter)
    {
        if (mbuyp.count(iter->first))
            result = (iter->second < mbuyp[iter->first] ? *iter : *mbuyp.find(iter->first));
        else
            result = *iter;
    }
//    printf("%.2f %d\n", result.first, result.second);//输出结果
    return 0;
}
