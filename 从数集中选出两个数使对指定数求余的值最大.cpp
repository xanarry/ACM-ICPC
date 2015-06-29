#include <algorithm>
#include <iostream>
using namespace std;
const int N=100005;
int a[N];
int main()
{
    int n,p;
    while(cin >> n)
    {   
        cin >> p;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            a[i] %= p;
        }
        sort(a, a+n);
        int ans = ((long long)a[n-1]+a[n-2])%p;
        for(int i = 0; i < n-1 && a[i] + a[i+1] < p; i++)
            ans=max(ans, a[i] + *(upper_bound(a+i+1, a+n, p-a[i]-1)-1));
        cout << ans << endl;
    }
    return 0;
}