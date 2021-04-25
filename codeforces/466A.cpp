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

	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if((double)(b)/m>=a)
		cout<<n*a;
	else{
		int cost=n/m*b;
		cost+=(n%m*a<b)?n%m*a:b;
		cout<<cost;
	}
}