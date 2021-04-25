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
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		char ch[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>ch[i][j];
		ll cost=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(ch[i][j]=='*')
					continue;
				else if(x<=(float)y/2||j==m-1||ch[i][j+1]=='*')
					cost+=x;
				else{
					cost+=y;
					j++;
				}
			}
		}
		cout<<cost<<'\n';
	}
}