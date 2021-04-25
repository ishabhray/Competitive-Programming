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

	ll n,x;
	cin>>n>>x;
	vv<ll> d(n*2);
	for(ll i=0;i<n;i++){
		cin>>d[i];
		d[n+i]=d[i];
	}
	vv<ll> pre(n*2+1),hug(n*2+1);
	ll mx=0;
	for(ll i=1;i<=2*n;i++)
		pre[i]=d[i-1]+pre[i-1],hug[i]=d[i-1]*(d[i-1]+1)/2+hug[i-1];
	for(ll i=1;i<=2*n;i++){
		if(pre[i]<x)
			continue;
		ll pos=upper_bound(pre.begin(),pre.end(),pre[i]-x)-pre.begin();
		ll h=hug[i]-hug[pos];
		//cout<<pos<<' '<<h<<' ';
		if(x>pre[i]-pre[pos]){
			ll left=x-pre[i]+pre[pos];
			//cout<<"$"<<left<<' ';
			h+=left*(left+1)/2+left*(d[pos-1]-left);
		}
		//cout<<h<<'\n';
		mx=(mx>h)? mx:h;
	}
	cout<<mx;
}