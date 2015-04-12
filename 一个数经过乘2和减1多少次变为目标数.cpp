#include <iostream>
#include <string>
using namespace std;
int flag=0,temp=0,ans=0;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n>m)
		cout<<n-m<<endl;
	else
	{
		while(n<m)
		{
			ans++;
			flag++;
			n*=2;
		}
		temp+=n-m;
		while(flag--)
		{
			ans+=temp%2;
			temp/=2;
		}
		ans+=temp;
		cout<<ans<<endl;
	}
	return 0;
}
