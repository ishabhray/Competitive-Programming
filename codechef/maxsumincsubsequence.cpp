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

	int n;
	cin>>n;
	int a[n+1]={0};
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int dp[n+1]={0};
	for(int i=0;i<=n;i++)
		dp[i]=a[i];
	for(int i=2;i<=n;i++){
		int mx=0;
		for(int j=1;j<i;j++){
			if(a[i]>a[j])
				mx=max(mx,dp[j]);
		}
		dp[i]+=mx;
	}
	for(int i=0;i<=n;i++){
		cout<<dp[i]<<' ';
	}
}