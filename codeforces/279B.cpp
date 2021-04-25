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

	ll n,t;
	cin>>n>>t;
	int a[n+1],b[n+1];
	a[0]=0,b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}
	int i=0,j=0;
	int mx=0;
	for(i=0;i<n;i++){
		while(j!=n&&b[j+1]-b[i]<=t)
			j++;
		mx=max(mx,j-i);
	}
	cout<<mx;
}