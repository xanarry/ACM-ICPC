/*
输入任意两个计算机能接受的实数,判断这两个实数是否相同
*/
#include <iostream>
#include <string>
using namespace std;

struct Num//保存一个实数的结构
{
    int zhengfu;//正负性
    string zhengshu;//整数部分
    string xiaoshu;//小数部分
};

Num mtrim(string str)
{
    Num a;
    //判断正负号并保存
    if (str[0] == '-')//-0.1 -1923 -23.231 -.002 -.7 -000.007123
    {
        a.zhengfu = -1;
        str = str.substr(1, str.length() - 1);
    }
    else if (str[0] == '+')// 00012 0.122 .12341 213.1231
    {
        a.zhengfu = 1;
        str = str.substr(1, str.length() - 1);
    }
    else
        a.zhengfu = 1;

    //粗提取整数部分
    int point_pos = str.length();
    point_pos = str.find('.') == string::npos ? str.length() : str.find('.');
    string t_zhengshu = str.substr(0, point_pos - 0);

    //粗提取小数部分
    string t_xiaoshu = "";
    if (point_pos < str.length())
        t_xiaoshu = str.substr(point_pos + 1, str.length() - point_pos);

    a.zhengshu = "";
    a.xiaoshu = "";

    //精确提取整数部分,清除前导0
    bool add = false;
    for (int i = 0; i < t_zhengshu.length(); i++)
    {
        if (t_zhengshu[i] != '0')
        {
            add = true;
            a.zhengshu += t_zhengshu[i];
        }
        else if (add == true)
            a.zhengshu += t_zhengshu[i];
    }

    //精确提取小数部分,清除后缀0
    add = false;
    for (int i = t_xiaoshu.length() - 1; i >= 0; i--)
    {
        if (t_xiaoshu[i] != '0')
        {
            add = true;
            a.xiaoshu = t_xiaoshu[i] + a.xiaoshu;
        }
        else if (add == true)
            a.xiaoshu = t_xiaoshu[i] + a.xiaoshu;
    }
    return a;
}

int cmp(Num a, Num b)
{
    //特殊检查,即整数小数部分都为0,处理后表现为长度空
    if (a.zhengshu.length() == 0 && a.xiaoshu.length() == 0 && b.zhengshu.length() == 0 && b.xiaoshu.length() == 0)
        return 0;

    if (a.zhengfu > b.zhengfu)//正负检查
        return 1;
    else if (a.zhengfu < b.zhengfu)
        return -1;
    else //同正或者同负
    {
        if (a.zhengshu.length() > b.zhengshu.length())//检查整数部分的长度
            return a.zhengfu > 0 ? 1 : -1;//要依据正负性做不同判断
        else if (a.zhengshu.length() == b.zhengshu.length())//整数部分位数相同
        {
            for (int i = 0; i < a.zhengshu.length(); i++)//比较每一位数
                if (a.zhengshu[i] != b.zhengshu[i])//相同的忽略,不同的是候检查,同样正负性相关
                    return a.zhengfu > 0 ? a.zhengshu[i] - b.zhengshu[i] : b.zhengshu[i] - a.zhengshu[i];
        }
        else
            return -1;

        //小数部分检查,从左对齐比较,如果所有比较的数字都相同,小数位数长度大的大,同样分正负
        for (int i = 0; i < min(a.xiaoshu.length(), b.xiaoshu.length()); i++)
            if (a.xiaoshu[i] != b.xiaoshu[i])
                return a.zhengfu > 0 ? a.xiaoshu[i] - b.xiaoshu[i] : b.xiaoshu[i] - a.xiaoshu[i];
        return a.zhengfu > 0 ? a.xiaoshu.length() - b.xiaoshu.length() : b.xiaoshu.length() - a.xiaoshu.length();
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a >> b)
    {
        Num n = mtrim(a), m = mtrim(b);
        int state = cmp(n, m);
        if (state == 0)
            cout << a << " = " << b << endl;
        else if (state > 0)
            cout << a << " > " << b << endl; 
        else if (state < 0 )
            cout << a << " < " << b << endl;  
    } 
    return 0;
}
