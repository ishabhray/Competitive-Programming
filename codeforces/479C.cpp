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
	vv<ii >v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.pb({a,b});
	}
	sort(v.begin(),v.end());
	int d=v[0].ss;
	for(auto a:v){
		if(d<=a.ss)
			d=a.ss;
		else
			d=a.ff;
	}
	cout<<d;
}