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


	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int dp[n][k+1];
		for(int i=0;i<n;i++){
			for(int j=0;j<=k;j++){
				dp[i][j]=INT_MAX;
				if(j==1)
					dp[i][j]=a[i];
			}
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[j]<=a[i]){
					for(int l=2;dp[j][l-1]!=INT_MAX&&l<=min(k,i+1);l++)
						dp[i][l]=min(dp[i][l],dp[j][l-1]+a[i]);
				}
			}
		}
		//for(int i=0;i<n;i++){
		//	for(int j=0;j<=k;j++){
		//		if(dp[i][j]==INT_MAX)
		//			cout<<"- ";
		//		else
		//			cout<<dp[i][j]<<' ';
		//	}
		//	cout<<'\n';
		//}
		int mn=INT_MAX;
		for(int i=0;i<n;i++)
			mn=min(mn,dp[i][k]);
		if(mn!=INT_MAX)
		cout<<mn<<'\n';
		else
			cout<<"-1\n";
	}
}