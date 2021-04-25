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
		int n;
		cin>>n;
		int h[n],k[n],mx=INT_MIN;
		for(int i=0;i<n;i++){
			cin>>h[i];
			if(h[i]>mx)
				mx=h[i];
		}
		for(int i=0;i<n;i++)
			cin>>k[i];
		int dp[1+2*mx];
		for(int i=1;i<=2*mx;i++)
			dp[i]=INT_MAX;
		dp[0]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j+k[i]<=2*mx;j++){
				if(dp[j]==INT_MAX)
					continue;
				dp[j+k[i]]=min(dp[j]+1,dp[j+k[i]]);
				//cout<<k[i]<<' '<<j<<' '<<dp[j+k[i]]<<'\n';
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++)
			cnt+=dp[2*h[i]];
		cout<<cnt<<'\n';
	}
}