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
		int n,m,k;
		cin>>n>>m>>k;
		if(m<=n/k)
			cout<<m<<'\n';
		else
			cout<<n/k-((m-n/k)/(k-1)+((m-n/k)%(k-1)!=0))<<'\n';
	}
}