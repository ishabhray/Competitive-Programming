#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

int n,a[(int)2e5],k;

int check(int m,int flag)
{
	int cnt=0;
	for(int i=0;i<n;i++){
		if(cnt==k)
			break;
		if(a[i]<=m || cnt%2!=flag)
			cnt++;
	}
	return cnt>=k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
	//cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		int l=1,r=1e9+1,ans=INT_MAX;
		while(l<=r){
			int m=(l+r)/2;
			if(check(m,0)||check(m,1)){
				ans=min(ans,m);
				r=m-1;
			}
			else
				l=m+1;
		}
		cout<<ans<<'\n';
	}
}