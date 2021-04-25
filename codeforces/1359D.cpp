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
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int mxs=0;
	for(int m=1;m<=30;m++){
		int b[n];
		bool f=false;
		for(int i=0;i<n;i++){
			if(a[i]==m)
				f=true;
			b[i]=(a[i]>m)?INT_MIN:a[i];
		}
		if(!f)
			continue;
		int mx=0,sum=0;
		for(int i=0;i<n;i++){
			sum+=b[i];
			sum=max(0,sum);
			mx=max(mx,sum);
		}
		mxs=max(mxs,mx-m);
	}
	cout<<mxs;
}