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

ll fact[(int)5e5+1];

int exp(int a,int b,int c)//finds a^b%c
{
	if(b==0)
		return 1;
	else{
		ll x=exp(a,b/2,c);
		x*=x;
		x=x%c;
		if(b%2==0)
			return x;
		else{
			x*=a;
			x=x%c;
			return x;
		}
	}
}

int inv(int a,int m)
{
	return exp(a,m-2,m);
}

int ncr(int n,int r)
{
	if(r>n)
		return 0;
	ll a=fact[n-r]*fact[r]%998244353;
	ll b=fact[n]*inv(a,998244353)%998244353;
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

	int n,k;
	cin>>n>>k;
	fact[0]=1;
	for(int i=1;i<=5e5;i++)
		fact[i]=i*fact[i-1]%998244353;
	ll ans=0;
	for(int i=1;i<=n;i++){
		int d=n/i;
		ans=(ans+ncr(d-1,k-1))%998244353;
	}
	cout<<ans<<'\n';
}