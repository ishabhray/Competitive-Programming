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
		int ne=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]%2==0)
				ne++;
		}
		if(ne%2==0)
			cout<<"YES\n";
		else{
			sort(a,a+n);
			int c=0;
			for(int i=1;i<n;i++)
				if(a[i]-a[i-1]==1)
					c=1;
			if(c)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		
	}
}