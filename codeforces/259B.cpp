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
#define C 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll a[3][3];
	for(ll i=0;i<3;i++)
		for(ll j=0;j<3;j++)
		cin>>a[i][j];
	a[0][0]=(a[0][2]+a[1][2]+a[0][1]+a[2][1]-a[1][0]-a[2][0])/2;
	a[1][1]=a[0][0]+a[0][2]-a[2][1];
	a[2][2]=a[0][0]+a[0][1]-a[1][2];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
}