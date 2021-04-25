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

int dp[6100][6100];

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

	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int n=s.size();
		int dp[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=0;
		for(int i=0;i<n;i++)
			dp[i][i]=1;
		for(int i=0;i<n;i++){
			for(int j=i-1;j>=0;j--){
				if(s[i]==s[j])
					dp[j][i]=2+dp[j+1][i-1];
				else
					dp[j][i]=max(dp[j][i-1],dp[j+1][i]);
			}
		}
		//for(int i=0;i<n;i++){
		//	for(int j=0;j<n;j++)
		//		cout<<dp[i][j];
		//	cout<<'\n';
		//}
		cout<<n-dp[0][n-1]<<'\n';
	}
}