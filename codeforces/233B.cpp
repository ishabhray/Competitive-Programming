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

ll sod(ll a){return (a)? a%10+sod(a/10):0;}

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
    ll ans=-1;
    for(int i=1;i<=90;i++){
    	ll l=1,r=1e9,mid;
    	while(l<=r){
    	    mid=(l+r)/2;
    	    ll x=mid*mid+i*mid;
    	    if(x==n&&sod(mid)==i){
    	    	ans=mid;
    	    	break;
    	    }
    	    else if(x==n)
    	    	break;
    	    else if(x<n)
    	    	l=mid+1;
    	    else
    	    	r=mid-1;
    	}
    	if(ans!=-1)
    		break;
    }
    cout<<ans;
}