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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int c=1,b[n];
		b[n-1]=1;
		for(int i=n-2;i>=0;i--){
			if((ll)a[i]*(ll)a[i+1]<0)
				b[i]=++c;
			else
				c=1,b[i]=1;
		}
		for(int i=0;i<n;i++)
			cout<<b[i]<<' ';
		cout<<'\n';
	}
}