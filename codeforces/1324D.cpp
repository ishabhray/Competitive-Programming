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
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	int sum[n];
	for(int i=0;i<n;i++)
		sum[i]=a[i]-b[i];
	sort(sum,sum+n);
	ll cnt=0;
	for(int i=0;i<n;i++){
		int pos=i+1;
		if(sum[i]<=0)
			pos=upper_bound(sum,sum+n,-sum[i])-sum;
		//cout<<pos<<' ';
		cnt+=n-pos;
	}
	cout<<cnt;
}