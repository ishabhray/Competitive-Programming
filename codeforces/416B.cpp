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
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0)
				continue;
			else if(i==0)
				a[i][j]+=a[i][j-1];
			else if(j==0)
				a[i][j]+=a[i-1][j];
			else
				a[i][j]+=max(a[i-1][j],a[i][j-1]);
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i][m-1]<<' ';
}