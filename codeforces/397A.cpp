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

	int n,l,r;
	cin>>n>>l>>r;
	vv< ii >v;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		if(x>=r||y<=l)
			continue;
		v.pb({x,y});
	}
	sort(v.begin(),v.end());
	int s=0,i=l;
	for(auto a:v){
		//cout<<a.ff<<' '<<a.ss<<' '<<i<<' '<<s<<'\n';
		if(a.ss<=i)
			continue;
		if(a.ff>=i)
			i=a.ff;
		if(a.ss>=r){
			s+=r-i;
			break;
		}
		s+=a.ss-i;
		i=a.ss;
	}
	cout<<r-l-s;
}