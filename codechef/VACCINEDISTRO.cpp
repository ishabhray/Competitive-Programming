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


int dp[2000][2000];

void dfs(int i,int vis[],vi adj[]){
	if(vis[i])
		return;
	vis[i]=1;
	for(int j:adj[i])
		dfs(j,vis,adj);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],b[n]={0};
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			b[max(i-a[i],0)]=max(i+a[i],b[max(i-a[i],0)]);
		int c=b[0];
		for(int i=1;i<n;i++){
			c=max(c,b[i]);
			b[i]=c;
		}
		//for(int i=0;i<n;i++)
		//	cout<<b[i]<<' ';
		int ans=0;
		for(int i=0;i<n;i++){
			ans++;
			i=b[i];
		}
		cout<<ans<<'\n';
	}
}