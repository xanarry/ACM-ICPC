/*
Description
有一些拥有50美分和一些拥有1美元人排队进电影院买票。
愚蠢的电影院开始卖票时1分钱也没有。现有一些排队买票的人，问是否每当一个拥有1美元的人买票时，电影院都有50美分找钱，如果可以输出Yes
不可以输出No
1美元=100美分拥有1美元的人，拥有的是纸币，没法破成2个50美分
拥有50美分的人用A表示。拥有1美元的人用B表示
Input
多组数据输入，每组数据一行，为一个仅由字母AB组成的字符串。
Output
“Yes”或者“No”
Sample Input
AAABB
ABABB
bbabaa
Sample Output
Yes
No
*/
#include <iostream>
using namespace std;

int main(){
    string s;
    int t = 0;
    while(cin >> s)
    {
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            if(s[i]=='A'){t++;}else{t--;} 
            if(t<0)break;
        }
        if(t<0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        t = 0;
    }
    return 0;
}