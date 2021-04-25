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
	map<int,int>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		m[x]++;
	}
	auto it=m.end();
	it--;
	int k=it->ff;
	ll a[k+1]={0};
	a[1]=m[1];
	for(int i=2;i<=k;i++){
		ll y=i;
		y*=m[i];
		a[i]=(a[i-1]>a[i-2]+y)?a[i-1]:a[i-2]+y;
	}
	cout<<max(a[k],a[k-1]);
}