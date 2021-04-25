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
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		vv<vi >v(k);
		for(int i=0;i<k;i++){
			for(int j=i;j<n;j+=k)
				v[i].pb(a[j]);
		}
		for(int i=0;i<k;i++)
			sort(v[i].begin(),v[i].end());
		sort(a,a+n);
		bool b=true;
		for(int i=0;i<n;i++){
			if(v[i%k][i/k]!=a[i]){
				b=false;
				break;
			}
		}
		if(b)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}