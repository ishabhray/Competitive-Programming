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

	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			cin>>ch;
			a[i][j]=ch-48;
		}
	}
	int dp[n][m];
	for(int i=0;i<m;i++)
		dp[n-1][i]=a[n-1][i]==1;
	for(int i=0;i<n;i++)
		dp[i][0]=a[i][0]==1;
	for(int i=n-2;i>=0;i--){
		for(int j=1;j<m;j++){
			dp[i][j]=0;
			if(a[i][j]!=0)
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
		}
	}
	//for(int i=0;i<n;i++){
	//	for(int j=0;j<m;j++)
	//		cout<<dp[i][j]<<' ';
	//	cout<<'\n';
	//}
	ll cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cnt+=dp[i][j];
	cout<<cnt<<'\n';
}