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

	int n,k,p;
	cin>>n>>k>>p;
	vv< ii >v(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.pb({x,i+1});
	}
	sort(v.rbegin(),v.rend());
	ll mx[n+1];
	mx[v[0].ss]=v[0].ff+k;
	for(int i=1;i<n;i++){
		if(v[i-1].ff-v[i].ff<=k)
			mx[v[i].ss]=mx[v[i-1].ss];
		else
			mx[v[i].ss]=v[i].ff+k;
	}
	for(int i=0;i<p;i++){
		int x,y;
		cin>>x>>y;
		if(mx[x]==mx[y])
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}