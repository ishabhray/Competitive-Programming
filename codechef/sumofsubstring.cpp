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

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		int a[n];
		for(int i=0;i<n;i++)
			a[i]=s[i]-48;
		ll dp[n+1][n+1];
		for(int i=0;i<n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=0;
		for(int i=0;i<n;i++)
			dp[i][1]=a[i];
		for(int i=n-2;i>=0;i--){
			for(int j=1;j<=n-i;j++)
				dp[i][j]=a[i]*(ll)pow(10,j-1)+dp[i+1][j-1];
		}
		ll sum=0;
		for(int i=0;i<n;i++)
			for(int j=1;j<=n;j++)
				sum+=dp[i][j];
		cout<<sum<<'\n';
	}
}