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
	int k=min(n,m)+1;
	cout<<k<<'\n';
	int i=n,j=0;
	while(k--){
		cout<<i<<' '<<j<<'\n';
		i--,j++;
		if(i<0)
			i=n;
		if(j>m)
			j=0;
	}
}