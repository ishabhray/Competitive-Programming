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
		int n,s;
		cin>>n>>s;
		s=100-s;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		int d=101,f=101;
		for(int i=0;i<n;i++){
			if(b[i]==0&&a[i]<d)
				d=a[i];
			else if(b[i]==1&&a[i]<f)
				f=a[i];
		}
		if(d+f<=s)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}