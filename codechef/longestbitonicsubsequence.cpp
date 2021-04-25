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
	int dp1[n]={0},dp2[n]={0};
	dp1[0]=1;
	dp2[n-1]=1;
	for(int i=1;i<n;i++){
		int mx=0;
		for(int j=0;j<i;j++){
			if(a[i]>a[j])
				mx=max(mx,dp1[j]);
		}
		dp1[i]=mx+1;
	}
	for(int i=n-2;i>=0;i--){
		int mx=0;
		for(int j=n-1;j>i;j--){
			if(a[i]>a[j])
				mx=max(mx,dp2[j]);
		}
		dp2[i]=mx+1;
	}
	for(int i=0;i<n;i++){
		cout<<dp1[i]<<' ';
	}
	cout<<'\n';
	for(int i=0;i<n;i++){
		cout<<dp2[i]<<' ';
	}
	int mx=0;
	for(int i=0;i<n;i++)
		mx=max(mx,dp1[i]+dp2[i]-1);
	cout<<'\n'<<mx;
}