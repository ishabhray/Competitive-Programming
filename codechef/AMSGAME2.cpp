#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<ll>
#define ii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

#define MAX 10000

ll gcd(ll a,ll b){return (b)?gcd(b,a%b):a;}

ll fun(ll ind,ll g, ll dp[][MAX+1],ll n, ll a[]){
	if(ind==n)
		return g==1;
	if(dp[ind][g]!=-1)
		return dp[ind][g];
	return dp[ind][g]=fun(ind+1,g,dp,n,a)+fun(ind+1,(g==0)?a[ind]:gcd(g,a[ind]),dp,n,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];
		ll dp[n][MAX+1];
		memset(dp,-1,sizeof dp);
		ll cnt=fun(0,0,dp,n,a);
		//for(ll i=0;i<n;i++){
		//	cnt+=fun(i+1,a[i],dp,n,a);
		//	for(ll i=0;i<n;i++){
		//		for(ll j=0;j<6;j++)
		//			cout<<dp[i][j]<<' ';
		//		cout<<'\n';
		//	}
		//	cout<<'\n';
		//}
		//for(ll i=0;i<n;i++)
		//	for(ll j=0;j<MAX;j++)
		//		if(dp[i][j]<-1)
		//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		cout<<cnt<<'\n';
	}
}