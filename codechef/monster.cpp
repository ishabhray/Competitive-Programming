#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
		int n;
		cin>>n;
		vector<pair<ll int,ll int> >v(n);
		for(int i=0;i<n;i++){
			ll int a,b;
			cin>>a>>b;
			v[i]={a,b};
		}
		ll int min=LONG_MAX,pos=-1;
		for(int i=0;i<n;i++){
			ll int x=v[(i+1)%n].first-max(0ll,v[(i+1)%n].first-v[i].second);
			if(x<min)
				min=x,pos=(i+1)%n;
		}
		ll int s=v[pos].first;
		for(int i=pos+1;i!=pos;i=(i+1)%n)
			s+=(ll)max(0ll,v[i].first-v[(n+i-1)%n].second);
		cout<<s<<'\n';
	}
}