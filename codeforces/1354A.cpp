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

ll min(ll a,ll b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		ll ans=b;
		ll rem=a-b;
		ll s=c-d;
		if(rem<=0)
			cout<<ans<<'\n';
		else if(s<=0)
			cout<<"-1\n";
		else{
			ans+=(rem+s-1)/s*c;
			cout<<ans<<'\n';
		}
	}
}