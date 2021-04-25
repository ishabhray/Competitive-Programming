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
	int l,r;
}seat;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	//#endif

	int n;
	string s;
	cin>>n>>s;
	vv<seat>v(n/2);
	for(int i=0;i<n/2;i++){
		if(s[i]=='L')
			v[i].l=i+1,v[i].r=i+1+n/2;
		else
			v[i].r=i+1,v[i].l=i+1+n/2;
	}
	for(auto a:v)
		cout<<a.l<<' '<<a.r<<'\n';
}