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
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		if(n*a==m*b){
			cout<<"YES\n";
			int i=0,a[n][m];
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					a[i][j]=0;
			for(int j=0;j<m;j++){
				for(int k=0;k<b;k++){
					a[i][j]=1;
					i++;
					if(i==n)
						i=0;
				}
			}
			for(i=0;i<n;i++){
				for(int j=0;j<m;j++)
					cout<<a[i][j];
				cout<<'\n';
			}
		}
		else
			cout<<"NO\n";
	}
}