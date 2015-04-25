/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=16133
计算小数的a的n次方,清除前导0和小数后面在末尾的0
方法:把小数当成不含小数的数进行高进度运算,然后取小数位数,然后清除前导后后缀0
*/
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

struct BigInteger
{
    static const int max_len = 1000;//数字的最大长度
    int num[max_len];//保存数字的每位数到数组，数字时逆序的，1234保存格式为4321
    int len;//数字的有效长度

    BigInteger(long long n)//构造函数，接收整数形式输入
    {
        len = 1;
        memset(num, 0, sizeof(num));
        if (n > 0)
        {
            int i = 0;
            while (n > 0)
            {
                num[i++] = n % 10;
                n /= 10;
            }
            len = i;
        }
    }

    BigInteger(string n)//构造函数接收字符串形式输入
    {
        memset(num, 0, sizeof(num));
        for (int i = n.length() - 1, t = 0; i >=0; i--)
            num[t++] = (int)(n[i] - '0');
        len = n.length();
    }

    BigInteger()//默认构造函数，初始值为0
    {
        len = 1;
        memset(num, 0, sizeof(num));
    }
    ~BigInteger(){}

    void clean()//清理掉数字前面的0，将“001509”，计算时表示为“905100”，将后面的0清除，整理为9051，最终输出1509
    {
        while (len > 1 && !num[len - 1])
            len--;
    }

    friend BigInteger operator* (BigInteger a, BigInteger b)//乘法，逆序
    {
        BigInteger result;//应为a,b两个数中的每个数要重复操作，所有开新的变量保存结果
        for (int i = 0; i < a.len; i++)//遍历乘数A
        {
            for (int j = 0; j < b.len; j++)//遍历乘数B
            {
                int temp = a.num[i] * b.num[j] + result.num[i + j];
                result.num[i + j] =  temp % 10;//取余数保存
                if (temp >= 10)//进位，错误相加同时进行
                    result.num[i + j + 1] += temp / 10;
            }
        }
        result.len = a.len + b.len;//两数相乘的最大乘数是两个乘数的长度之和
        result.clean();
        return result;
    }

    friend ostream& operator << (ostream &os, const BigInteger n)
    {
        for (int i = n.len - 1; i >= 0; i--)
            os << n.num[i];
        return os;
    }

    friend istream& operator >> (istream &is, BigInteger &n)
    {
        string s;
        is >> s;
        n = BigInteger(s);
        return is;
    }
};

int main(int argc, char const *argv[])
{
    string a;
    int b;
    while (cin >> a >> b)//输入一个小数(字符串), 和次方数
    {
        //处理0.00123这种形式的数,将其变为123
        stringstream ss;
        int flag = 0;
        while (a[flag] == '0' || a[flag] == '.')
            flag++;
        for (int i = flag; i < a.length(); i++)
            if (a[i] != '.')
                ss << a[i];

        //查找小数点的位置,并计算次方运算后小数的位数
        unsigned pos = a.find(".");
        int weishu = 0;
        if (pos != string::npos)
            weishu = a.length() - a.find(".") - 1;
        weishu *= b;
        
        //定义两个大整数开始运算
        BigInteger R, ctr = 1;
        ss >> R;
        for (int i = 0; i < b; i++)//不断乘b次,即b次方
            ctr = ctr * R;

        //将大整数转换为字符串
        stringstream ssr, sswp;
        ssr << ctr;
        string sresult = ssr.str();

        //处理计算结果中小数点后的后缀0:12.32100000
        bool postzero = true;
        for (int i = sresult.length() - 1, mark = 0; i >= 0 || mark <= weishu; i--, mark++)
        {
            if (i >= 0)
            {
                if (mark == weishu)
                    sswp << ".";

                if (sresult[i] != '0')//not zero
                {
                    sswp << sresult[i];
                    postzero = false;
                }
                else//zero 10000
                    if (postzero == false || mark >= weishu)
                        sswp << sresult[i];
            }
            else
            {
                if (mark == weishu)
                    sswp << '.';
                sswp << "0";
            }
        }
        
        string re = sswp.str();
        //处理前导0
        flag = re.length() - 1;
        while (re[flag] == '0')
            flag--;
        //预防输出12.这样的结果,最后一位单独判断输出,计算出的结果是逆序的,所有从后向前输出字符
        for (int i = flag; i > 0; i--)
            cout << re[i];
        //判读最后一位是否为'.'
        if (re[0] != '.')
            cout << re[0];
        cout << endl;
    }
    return 0;
}