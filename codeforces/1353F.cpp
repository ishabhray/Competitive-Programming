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

ll min(ll a,ll b)
{
	if(a<b)
		return a;
	else
		return b;
}
int n,m;
ll a[100][100];
ll min_cost(ll x)
{
	//cout<<x<<":\n";
	ll dp[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ll y=x+i+j;
			if(i==0&&j==0)
				dp[i][j]=0;
			else if(y>a[i][j])
				dp[i][j]=1e18;
			else if(i==0)
				dp[i][j]=dp[i][j-1]+a[i][j]-y;
			else if(j==0)
				dp[i][j]=dp[i-1][j]+a[i][j]-y;
			else
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j]-y;
		}
	}
	//for(int i=0;i<n;i++){
	//	for(int j=0;j<m;j++)
	//		cout<<dp[i][j]<<' ';
	//	cout<<'\n';
	//}
	return dp[n-1][m-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		ll ans=1e18;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ll x=a[i][j]-i-j;
				if(x>a[0][0])
					continue;
				ans=min(ans,min_cost(x)+a[0][0]-x);
			}
		}
		cout<<ans<<'\n';
	}
}