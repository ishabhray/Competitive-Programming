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

	int n,m,k;
	cin>>n>>m>>k;
	int a[n+1][m+1];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			a[i][j]=0;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		if(a[x][y]==0){
			a[x][y]=1;
			cout<<x<<' '<<y<<'\n';
		}
		else{
			
		}
	}