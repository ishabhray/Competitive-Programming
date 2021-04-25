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
	return (a<b)?a:b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j==0||i==j)
				dp[i][j]=1;
			else if(j>i)
				dp[i][j]=-1;
			else
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}
}