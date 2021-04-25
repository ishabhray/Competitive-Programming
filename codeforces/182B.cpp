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

int gcd(int a,int b){return (b)?gcd(b,a%b):a;}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,d;
	cin>>d>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=0;i<n-1;i++)
		cnt+=d-a[i];
	cout<<cnt;
}