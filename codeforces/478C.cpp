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

	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	ll x=(ll)a[0]+a[1];
	if(x<=a[2]/2)
		cout<<x;
	else{
		x+=a[2];
		cout<<x/3;
	}
}