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

	int n;
	cin>>n;
	map<int,vi>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		m[x].pb(i);
	}
	vv<ii >v;
	for(auto a:m){
		if(a.ss.size()==1)
			v.pb({a.ff,0});
		else{
			int d=a.ss[1]-a.ss[0];
			bool b=true;
			for(int i=2;i<a.ss.size();i++){
				if(a.ss[i]-a.ss[i-1]!=d){
					b=false;
					break;
				}
			}
			if(b)
				v.pb({a.ff,d});
		}
	}
	cout<<v.size()<<'\n';
	for(auto a:v)
		cout<<a.ff<<' '<<a.ss<<'\n';
}