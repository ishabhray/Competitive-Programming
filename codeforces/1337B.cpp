#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int x,n,m;
		cin>>x>>n>>m;
		while(x>=20&&n>0){
			x=x/2+10;
			n--;
		}
		x-=m*10;
		if(x<=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}