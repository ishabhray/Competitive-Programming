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
#define M_PI       3.14159265358979323846

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll dp[n];
	dp[0]=1,dp[1]=2;
	for(ll i=2;i<n;i++){
		if(a[i]==a[i-1]+a[i-2])
			dp[i]=dp[i-1]+1;
		else dp[i]=2;
	}
	ll mx=0;
	for(ll i=0;i<n;i++){
		//cout<<dp[i]<<' ';
		if(dp[i]>mx)
			mx=dp[i];
	}
	cout<<mx;
}