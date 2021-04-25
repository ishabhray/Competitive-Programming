#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,h,l,r;
	cin>>n>>h>>l>>r;
	int a[n],pre[n+1];
	pre[0]=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pre[i+1]=pre[i]+a[i];
	}
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=INT_MIN;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0]+(pre[i]%h>=l&&pre[i]%h<=r);
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+((pre[i]-j)%h>=l&&(pre[i]-j)%h<=r);
		}
	}
	
	int mx=INT_MIN;
	for(int i=0;i<=n;i++)
		mx=max(dp[n][i],mx);
	cout<<mx;
}