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


ll dp[2000][2000];

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
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=0;
		for(int i=0;i<n;i++){
			for(int j=i;j>=0;j--){
				if(i==j)
					dp[i][j]=1;
				else if(j==i-1){
					if(s[i]==s[j])
						dp[j][i]=2;
					else dp[j][i]=1;
				}
				else if(s[i]==s[j]){
					if(dp[j+1][i-1]==i-j-1)
						dp[j][i]=dp[j+1][i-1]+2;
					else
						dp[j][i]=dp[j+1][i-1];
				}
				else
					dp[j][i]=max(dp[j+1][i],dp[j][i-1]);
			}
		}
		ll ans=0;
		for(int i=0;i<n-1;i++){
			ans=max(ans,dp[0][i]*dp[i+1][n-1]);
		}
		cout<<ans<<'\n';
		
	}
}