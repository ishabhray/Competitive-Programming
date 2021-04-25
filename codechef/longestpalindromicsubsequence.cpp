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


int dp[100][100];

int lps(string s,int i,int j){
	if(dp[i][j]!=0)
		return dp[i][j];
	else if(i>j)
		dp[i][j]=0;
	else if(i==j)
		dp[i][j]=1;
	else if(s[i]==s[j])
		dp[i][j]=2+lps(s,i+1,j-1);
	else
		dp[i][j]=max(lps(s,i+1,j),lps(s,i,j-1));
	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			dp[i][j]=0;
	cout<<lps(s,0,n-1)<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}
}