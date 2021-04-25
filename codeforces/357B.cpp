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
	map<int,int>M;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(M[x]==0){
			for(int i=1;i<=3;i++){
				if(M[y]!=i&&M[z]!=i){
					M[x]=i;
					break;
				}
			}
		}
		if(M[y]==0){
			for(int i=1;i<=3;i++){
				if(M[x]!=i&&M[z]!=i){
					M[y]=i;
					break;
				}
			}
		}
		M[z]=6-M[x]-M[y];
	}
	for(auto a:M)
		cout<<a.ss<<' ';
}