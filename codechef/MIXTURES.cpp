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

	int n;
	//cin>>T;
	while(cin>>n){
		int a[n],pre[n+1]={0};
		for(int i=0;i<n;i++){
			cin>>a[i];
			pre[i+1]=a[i]+pre[i];
		}
		ll dp[n+1][n+1];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j]=0;
		for(int l=2;l<=n;l++){
			for(int i=1;i+l-1<=n;i++){
				dp[i][i+l-1]=LONG_MAX;
				for(int k=i;k<i+l-1;k++){
					int cost=((pre[i+l-1]-pre[k])%100)*((pre[k]-pre[i-1])%100)+dp[k+1][i+l-1]+dp[i][k];
					dp[i][i+l-1]=(dp[i][i+l-1]>cost)?cost:dp[i][i+l-1];
				}
			}
		}
		//for(int i=0;i<=n;i++){
		//	for(int j=0;j<=n;j++)
		//		cout<<dp[i][j]<<'\t';
		//	cout<<'\n';
		//}
		cout<<dp[1][n]<<'\n';
	}
}