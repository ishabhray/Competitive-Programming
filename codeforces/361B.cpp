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

int gcd(int a,int b){return (b)?gcd(b,a%b):a;}

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
	if(k==n)
		cout<<-1;
	else{
		cout<<n-k<<' ';
		for(int i=1;i<=n-k-1;i++)
			cout<<i<<' ';
		for(int i=n-k+1;i<=n;i++)
			cout<<i<<' ';
	}
}