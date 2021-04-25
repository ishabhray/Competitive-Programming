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
		int a,b;
		cin>>a>>b;
		int min=(a<b)? a:b;
		int max=a+b-min;
		if(min<=max/2)
			cout<<max*max<<'\n';
		else
			cout<<4*min*min<<'\n';
	}
}