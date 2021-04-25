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

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int c=0;
		if(n<=k)
			c=n;
		else{
			for(int i=1;i<=min(int(sqrt(n)),k);i++)
				if(n%i==0)
					c=max(c,(n/i<=k)? n/i:i);
		}
		cout<<n/c<<'\n';
	}
}