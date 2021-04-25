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
#define C 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll n,s,t;
	cin>>n>>s>>t;
	ll cnt=0;
	ll v[n+1]={0},a[n+1];
	v[s]=1;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	while(s!=t&&a[s]!=s){
		s=a[s];
		cnt++;
		if(v[s]==1)
			break;
	}
	if(s==t)
		cout<<cnt;
	else
		cout<<-1;
}