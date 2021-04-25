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

	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int x=min(min(a,b),c);
	int z=max(max(a,b),c);
	int y=a+b+c-x-z;
	int dp[n+1];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i<x)
			dp[i]=-5000;
		else if(i<y)
			dp[i]=1+dp[i-x];
		else if(i<z)
			dp[i]=1+max(dp[i-x],dp[i-y]);
		else
			dp[i]=1+max(max(dp[i-x],dp[i-y]),dp[i-z]);
	}
	cout<<dp[n];
}