/*
将n个球放入m个盒子，有多少种放法
*/#include <iostream>
using namespace std;
const int MAX=20;
long long dp[MAX][MAX];
void Init()
{
	for(int i=1;i<=15;i++)
		for(int j=1;j<=i;j++)
			if(j==i || j==1)
				dp[i][j]=1;
			else
//将i个球放到j个盒子中有两种情况，即将i-1个求放到j-1个盒子，加上i-1个球放到j个盒子乘上剩下的一个球可以放到任意j个盒子中
				dp[i][j]=dp[i-1][j-1]+j*dp[i-1][j];
}

int main()
{
	int n,m;
	Init();
	while(cin>>n>>m)
		cout<<dp[n][m]<<endl;
	return 0;
}
