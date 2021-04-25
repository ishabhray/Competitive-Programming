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
	int p[n+1];
	p[0]=0;
	for(int i=1;i<=(n+1)/2;i++){
		int x;
		cin>>x;
		p[i]=p[i-1]+x;
	}
	int x;
	cin>>x;
	for(int i=(n+1)/2+1;i<=n;i++)
		p[i]=p[i-1]+x;
	if(p[n]>0)
		cout<<n;
	else if(x>=0)
		cout<<-1;
	else{
		ll max=-INF;
		for(int i=0)
	}
}