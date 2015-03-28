/*
输入一个数字n，输出连续自然数之和等于n的情况总数
5=5;        5=2+3; 输出 2
10=10;  10=1+2+3+4; 输出 2
*/
#include <iostream>
using namespace std;

int main(){
    int i, ans;
    double n, t;
    while(cin>>n) {
        ans = 0;
        for(i = 1; (1+i)*i/2 <= n; i++) {
            t = n/i;
            if(i%2 == 0) {
                if(t-(int)t == 0.5) ans++;
            } else {
                if(t==(int)t) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int t = 1;
        for (int i = 1; i <= n / 2; i++)
        {
            int sum = 0;
            for (int j = i, c = 0; c <= sqrt(2 * n); c++)
            {
                if (sum < n)
                    sum += j++;
                else
                    break;
            }
            if (sum == n)
                t++;
        }
        cout << t << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    long long n,i;
    while(cin>>n)
    {
        long long sum=0;
        for(i=1;sum+i<=n;i++)
            sum+=i;
        int part=i-1,ans=0;
        long long over=n-sum;
        while(part!=0)
        {
            //cout<<"over: "<<over<<" part: "<<part<<endl;
            if(over%part==0)
                ans++;
            over+=part;
            part--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/