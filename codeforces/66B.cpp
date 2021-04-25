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
	int l[n],r[n];
	l[0]=1;r[n-1]=1;
	for(int i=1;i<n;i++){
		if(a[i]>=a[i-1])
			l[i]=l[i-1]+1;
		else
			l[i]=1;
	}
	for(int i=n-2;i>=0;i--){
		if(a[i]>=a[i+1])
			r[i]=r[i+1]+1;
		else
			r[i]=1;
	}
	int mx=0;
	for(int i=0;i<n;i++)
		mx=max(mx,l[i]+r[i]-1);
	cout<<mx;
}