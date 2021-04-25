#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pint pair<int,int>
#define vv vector
#define C 1000000007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int T=1;
	//cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=0;i<=n;i++)
			cin>>a[i];
		int dp[n+1][n+1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=0;
		for(int l=2;l<=n;l++){
			for(int i=1;i+l-1<=n;i++){
				dp[i][i+l-1]=INT_MAX;
				for(int k=i;k<i+l-1;k++){
					int cost=a[i-1]*a[k]*a[i+l-1]+dp[k+1][i+l-1]+dp[i][k];
					dp[i][i+l-1]=min(dp[i][i+l-1],cost);
				}
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)
				cout<<dp[i][j]<<'\t';
			cout<<'\n';
		}
		cout<<"ANS:"<<dp[1][n];
	}
}