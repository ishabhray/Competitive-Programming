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
		int x,y;
		cin>>x>>y;
		v.pb({x,y});
	}
	sort(v.begin(),v.end());
	int max=v[0].ss;
	bool b=false;
	for(int i=1;i<n;i++){
		if(v[i].ss<max){
			b=true;
			break;
		}
		if(v[i].ss>max)
			max=v[i].ss;
	}
	if(b)
		cout<<"Happy Alex";
	else
		cout<<"Poor Alex";
}