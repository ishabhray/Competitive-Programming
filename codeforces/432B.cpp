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

typedef struct{
	int h,a;
}team;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll n;
	cin>>n;
	team t[n];
	map<int,int> x,y;
	for(int i=0;i<n;i++){
		cin>>t[i].h>>t[i].a;
		x[t[i].h]++;
		y[t[i].a]++;
	}
	for(int i=0;i<n;i++){
		ll cnt=n-1;
		cnt+=x[t[i].a];
		cout<<cnt<<' '<<2*(n-1)-cnt<<'\n';
	}
}